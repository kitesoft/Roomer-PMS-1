unit uCSVData;

interface

uses
  Classes;

type
  TCSVData = class
  private
    FData: array of array of string;
    FDelim: Char;
    FQuote: Char;
    function GetRows: Integer;
    function GetCols: Integer;
    function GetCell(Row, Col: Integer): string;
    procedure SetCell(Row, Col: Integer; const Value: string);
  public
    destructor Destroy; override;
    procedure LoadFromFile(const FileName: string);
    procedure LoadFromStrings(const data: TStringList);
    property Cell[Row, Col: Integer]: string read GetCell write SetCell;
    property Rows: Integer read GetRows;
    property Cols: Integer read GetCols;
    property Delim: Char read FDelim write FDelim;
    property Quote: Char read FQuote write FQuote;
  end;

implementation

{ TCSVData }

destructor TCSVData.Destroy;
begin
  SetLength(FData, 0, 0);
  inherited;
end;

function TCSVData.GetCell(Row, Col: Integer): string;
begin
  Result := FData[Row, Col];
end;

function TCSVData.GetCols: Integer;
begin
  if Rows > 0 then
    Result := Length(FData[0])
  else
    Result := 0;
end;

function TCSVData.GetRows: Integer;
begin
  Result := Length(FData);
end;

procedure TCSVData.LoadFromStrings(const data: TStringList);
var
  Val: string;
  MyChar: Char;
  LastChar: Char;
  QuotePart: Boolean;
  Col: Integer;
  Row: Integer;
  MaxCol: Integer;
begin
  LastChar := #0;
  QuotePart := False;
  Val := '';
  MaxCol := 0;
  Col := 0;
  Row := 0;

  // Jedes Zeichen durchlaufen
  for MyChar in data.Text do
  begin
    if (MyChar = Quote) then
    begin
      // QuotePart wechselt den Status
      QuotePart := not QuotePart;

      // Befinden wir uns im QuotePart und das letzte Zeichen
      // war das Quote-Zeichen, dann handelt es sich um eine
      // Verdoppelung und wir hängen das Quote-Zeichen an
      // den Puffer
      if QuotePart and (LastChar = Quote) then
        Val := Val + Quote;
    end
    else
    if not QuotePart and (MyChar = Delim) then
    begin
      // Sind noch nicht genug Zeilen da ...
      if high(FData) < Row + 1 then
        // ... dann auf Verdacht schon mal 10 hinzufügen
        SetLength(FData, Row + 10);
      // Sind noch nicht genug Spalten da ...
      if high(FData[Row]) < Col + 1 then
        // ... dann auf Verdacht schon mal 10 hinzufügen
        SetLength(FData[Row], Col + 10);
      // Wert eintragen
      FData[Row, Col] := Val;
      // Puffer leeren
      Val := '';
      // Spalte hochzählen
      Inc(Col);
    end
    else
    if not QuotePart and ((MyChar = #13) or (MyChar = #10)) then
    begin
      // Haben wir CR LF gefunden ...
      if (MyChar = #10) and (LastChar = #13) then
      begin
        // Sind noch nicht genug Zeilen da ...
        if high(FData) < Row + 1 then
          // ... dann auf Verdacht schon mal 10 hinzufügen
          SetLength(FData, Row + 10);
        // Die Anzahl der Spalten steht jetzt fest
        SetLength(FData[Row], Col + 1);
        // MaxCol merken
        if Col > MaxCol then
          MaxCol := Col;
        // Wert eintragen
        FData[Row, Col] := Val;
        // Puffer leeren
        Val := '';
        // Zeile hochzählen
        Inc(Row);
        // Neue Zeile => erste Spalte
        Col := 0;
      end
      else
        Val := Val + MyChar;
    end
    else
      // Das aktuelle Zeichen an den Puffer hängen
      Val := Val + MyChar;
    // Das letzte Zeichen merken
    LastChar := MyChar;
  end;

  SetLength(FData, Row);

  // Das ist eigentlich nur notwendig, wenn die CSV-Datei falsch aufgebaut ist
  // und unterschiedliche Anzahl von Spalten in den Zeilen aufweist
  // Dieses ist allerdings nicht RFC-konform, aber wir wollen mal nicht so sein
  for Row := low(FData) to high(FData) do
    SetLength(FData[Row], MaxCol + 1);

end;

procedure TCSVData.LoadFromFile(const FileName: string);
var
  data: TStringList;
begin
  data := TStringList.Create;
  try
    data.LoadFromFile(FileName);
    LoadFromStrings(data);
  finally
    data.Free;
  end;
end;

procedure TCSVData.SetCell(Row, Col: Integer; const Value: string);
begin
  FData[Row, Col] := Value;
end;

end.
