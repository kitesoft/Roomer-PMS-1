unit uAmount;

interface

type

  TAmount = record
    Value: double;
    Currency: string[5];

    class operator Implicit(a: TAmount): double;
    class operator Implicit(a: TAmount): integer;

    class operator Add(a, b: TAmount): TAmount;
    class operator Subtract(a, b: TAmount): TAmount;
    class operator Equal(a, b: TAmount): boolean;
  end;

implementation

{ TAmount }

class operator TAmount.Add(a, b: TAmount): TAmount;
begin

end;

class operator TAmount.Equal(a, b: TAmount): boolean;
begin

end;


class operator TAmount.Implicit(a: TAmount): double;
begin

end;

class operator TAmount.Implicit(a: TAmount): integer;
begin

end;

class operator TAmount.Subtract(a, b: TAmount): TAmount;
begin

end;

end.
