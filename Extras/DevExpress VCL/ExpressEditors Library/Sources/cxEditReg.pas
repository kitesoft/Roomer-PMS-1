{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{       ExpressEditors                                               }
{                                                                    }
{       Copyright (c) 1998-2014 Developer Express Inc.               }
{       ALL RIGHTS RESERVED                                          }
{                                                                    }
{   The entire contents of this file is protected by U.S. and        }
{   International Copyright Laws. Unauthorized reproduction,         }
{   reverse-engineering, and distribution of all or any portion of   }
{   the code contained in this file is strictly prohibited and may   }
{   result in severe civil and criminal penalties and will be        }
{   prosecuted to the maximum extent possible under the law.         }
{                                                                    }
{   RESTRICTIONS                                                     }
{                                                                    }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES            }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE     }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS    }
{   LICENSED TO DISTRIBUTE THE EXPRESSEDITORS AND ALL                }
{   ACCOMPANYING VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY. }
{                                                                    }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED       }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE         }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE        }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT   }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                       }
{                                                                    }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON        }
{   ADDITIONAL RESTRICTIONS.                                         }
{                                                                    }
{********************************************************************}

unit cxEditReg;

{$I cxVer.inc}

interface

uses
  Classes, Controls, DB, DesignIntf, DSDesign, cxEdit;

type
  { TcxFieldsTarget }

  TcxFieldsTarget = class(TDragTarget)
  protected
    procedure CreateControls(AFieldList: TList; AEditor: TFieldsEditor; ATarget: TObject; X, Y: Integer);
    procedure DoCreateFieldControl(AParent, AControl: TControl; AField: TField); virtual;
    function GetAllowTarget(ATarget: TControl): TControl;
    function GetControlClass(AEditor: TFieldsEditor; AField: TField): string; virtual;
    function NeedCreateCaption(ATarget: TControl): Boolean;
  public
    procedure DragDrop(Target, Source: TObject; X, Y: Integer); override;
    function DragOver(Target, Source: TObject; X, Y: Integer; State: TDragState): Boolean; override;
  end;

  TcxGetControlClassNameProc = procedure (AField: TField; out AClassName: string);

  TcxFieldsTargetClass = class of TcxFieldsTarget;

procedure cxRegisterDragTarget(ATargetClass: TcxFieldsTargetClass);
procedure cxUnregisterDragTarget(ATargetClass: TcxFieldsTargetClass);

function cxCreateFieldControl(ADesigner: IDesigner; AField: TField; AParent: TWinControl; X, Y: Integer): TControl;

var
  cxGetControlClassNameProc: TcxGetControlClassNameProc;

procedure Register;

implementation

uses
  DesignEditors, VCLEditors, Windows, Graphics, ImgList, TypInfo,
  DsnDBCst, DrpCtrls, SysUtils, Dialogs, Forms,
  dxCore, cxControls, cxBlobEdit, cxButtonEdit, cxButtons, cxCalc, cxCalendar, cxCheckBox,
  cxContainer, cxCurrencyEdit, cxDB, cxDBEdit, cxDBEditRepository, cxDBLookupComboBox,
  cxDBNavigator, cxDropDownEdit, cxEditConsts, cxEditPropEditors, cxEditRepositoryEditor,
  cxEditRepositoryItems, cxGraphics, cxGroupBox, cxHyperLinkEdit, cxImage,
  cxImageComboBox, cxLibraryReg, cxListBox, cxLookAndFeels, cxLookupDBGrid,
  cxLookupGrid, cxMaskEdit, cxMemo, cxMRUEdit, cxNavigator, cxPropEditors,
  cxRadioGroup, cxSpinEdit, cxTextEdit, cxTimeEdit, cxScrollBox, dxBevel,
  dxBreadcrumbEdit, dxDBBreadcrumbEdit, dxAlertWindow, dxGalleryControl,
  dxColorGallery, dxDBColorGallery, dxImageSlider, dxCheckGroupBox, dxDBCheckGroupBox,
  cxCustomData;

type
  TcxCustomEditAccess = class(TcxCustomEdit);

  { TcxLookupComboBoxPropertiesFieldNameProperty }

  TcxLookupComboBoxPropertiesFieldNameProperty = class(TFieldNameProperty)
    function GetDataSourcePropName: string; override;
  end;

  { TcxLookupDBGridColumnFieldNameProperty }

  TcxLookupDBGridColumnFieldNameProperty = class(TFieldNameProperty)
  public
    function GetDataSource: TDataSource; override;
  end;

  { TcxDateEditSelectionEditor }

  TcxDateEditSelectionEditor = class(TSelectionEditor)
  protected
    ComponentsList: TStringList;
  public
    procedure RequiresUnits(Proc: TGetStrProc); override;
  end;

  TcxLookupDBGridColumnAccess = class(TcxLookupDBGridColumn);

  { TcxDragFields }

  TcxDragFields = class(TDragControlObject)
  private
    FEditor: TFieldsEditor;
  public
    constructor Create(AControl: TControl; AEditor: TFieldsEditor); reintroduce;
    property Editor: TFieldsEditor read FEditor;
  end;

  { TdxAlertWindowManagerSelectionEditor }

  TdxAlertWindowManagerSelectionEditor = class(TSelectionEditor)
  public
    procedure RequiresUnits(Proc: TGetStrProc); override;
  end;

function cxGetControlClassName(AField: TField): string;
begin
  Result := '';
  if Assigned(cxGetControlClassNameProc) then
    cxGetControlClassNameProc(AField, Result);
end;

var
  FRegisteredDragTargets: TList;

procedure InternalRegisterDragTarget(ATargetClass: TDragTargetClass);
begin
  RegisterDragTarget('TDragFields', ATargetClass);
end;

procedure cxRegisterDragTarget(ATargetClass: TcxFieldsTargetClass);
begin
  InternalRegisterDragTarget(ATargetClass);
  FRegisteredDragTargets.Add(ATargetClass);
end;

procedure cxUnregisterDragTarget(ATargetClass: TcxFieldsTargetClass);
begin
  FRegisteredDragTargets.Remove(ATargetClass);
  if FRegisteredDragTargets.Count > 0 then
    InternalRegisterDragTarget(FRegisteredDragTargets.Last);
end;

function InternalCreateFieldControl(ADesigner: IDesigner; AField: TField; AControlClassName: string;
  AParent: TControl; X, Y: Integer; ANeedCreateCaption: Boolean): TControl;
var
  ADataBinding: TcxDBEditDataBinding;
begin
  Result := CreateFieldControl(ADesigner, AField, AControlClassName, AParent, X, Y, ANeedCreateCaption);
  if Result is TcxCustomEdit then
  begin
    ADataBinding := TcxDBEditDataBinding(TcxCustomEditAccess(Result).DataBinding);
    ADataBinding.DataSource := GetDataSource(ADesigner, AField.DataSet);
    ADataBinding.DataField := AField.FieldName;
  end;
end;

function cxCreateFieldControl(ADesigner: IDesigner; AField: TField; AParent: TWinControl; X, Y: Integer): TControl;
begin
  Result := InternalCreateFieldControl(ADesigner, AField, cxGetControlClassName(AField), AParent, X, Y, False);
end;

{ TcxDragFields }

constructor TcxDragFields.Create(AControl: TControl; AEditor: TFieldsEditor);
begin
  inherited Create(AControl);
  FEditor := AEditor;
end;

{ TdxAlertWindowManagerSelectionEditor }

procedure TdxAlertWindowManagerSelectionEditor.RequiresUnits(Proc: TGetStrProc);
begin
  Proc('cxLookAndFeelPainters');
  Proc('cxGraphics');
  dxSkinsRequiresAdditionalUnits(nil, Proc);
end;

{ TcxLookupComboBoxPropertiesFieldNameProperty }

function TcxLookupComboBoxPropertiesFieldNameProperty.GetDataSourcePropName: string;
begin
  Result := 'ListSource';
end;

{ TcxLookupDBGridColumnFieldNameProperty }

function TcxLookupDBGridColumnFieldNameProperty.GetDataSource: TDataSource;
begin
  Result := TcxLookupDBGridColumnAccess(GetComponent(0) as TcxLookupDBGridColumn).DataController.DataSource;
end;

{ TcxDateEditSelectionEditor }

procedure TcxDateEditSelectionEditor.RequiresUnits(Proc: TGetStrProc);
begin
{$IFDEF DELPHI16}
  Proc('Vcl.ComCtrls');
{$ELSE}
  Proc('ComCtrls');
{$ENDIF}
  Proc('dxCore');
  Proc('cxDateUtils');
end;

{ TcxFieldsTarget }

procedure TcxFieldsTarget.DragDrop(Target, Source: TObject; X, Y: Integer);
var
  ASourceRoot: TComponent;
  I: Integer;
  AEditor: TFieldsEditor;
  AFieldList: TList;
begin
  ASourceRoot := TcxDragFields(Source).Editor.Designer.GetRoot;
  if not Designer.IsComponentLinkable(ASourceRoot) then
    if MessageDlg(Format(SDSLinkForms, [Designer.GetRoot.Name,
      ASourceRoot.Name]), mtConfirmation, mbYesNoCancel, 0) <> idYes then
        Exit
    else
      Designer.MakeComponentLinkable(ASourceRoot);
  AFieldList := TList.Create;
  try
    AEditor := TcxDragFields(Source).Editor;
    with AEditor do
    begin
      for I := 0 to FieldListBox.Items.Count - 1 do
        if FieldListBox.Selected[I] then
          AFieldList.Add(FieldListBox.Items.Objects[I]);
    end;
    if AFieldList.Count > 0 then
    begin
      Screen.Cursor := crHourGlass;
      try
        CreateControls(AFieldList, AEditor, Target, X, Y);
      finally
        Screen.Cursor := crDefault;
      end;
    end;
  finally
    AFieldList.Free;
  end;
end;

procedure TcxFieldsTarget.CreateControls(AFieldList: TList; AEditor: TFieldsEditor; ATarget: TObject; X, Y: Integer);
var
  I: Integer;
  ADataSource: TDataSource;
  AField: TField;
  AControl: TControl;
  AParent: TControl;
  AIntf: IcxEditorFieldLink;
  ANeedCreateCaption: Boolean;
begin
  AField := TField(AFieldList[0]);
  ADataSource := GetDataSource(Designer, AField.DataSet);
  AParent := GetAllowTarget(ATarget as TControl);
  if not Supports(AParent, IcxEditorFieldLink, AIntf) or not AIntf.CreateFieldControls(X, Y, ADataSource, AFieldList) then
  begin
    ANeedCreateCaption := NeedCreateCaption(AParent);
    for I := 0 to AFieldList.Count - 1 do
    begin
      AField := TField(AFieldList[I]);
      AControl := InternalCreateFieldControl(Designer, AField, GetControlClass(AEditor, AField),
        AParent, X, Y, ANeedCreateCaption);
      DoCreateFieldControl(AParent, AControl, AField);
      Y := AControl.Top + AControl.Height + 5;
    end;
  end;
end;

procedure TcxFieldsTarget.DoCreateFieldControl(AParent, AControl: TControl; AField: TField);
var
  AIntf: IcxEditorFieldLink2;
begin
  if Supports(AParent, IcxEditorFieldLink2, AIntf) then
    AIntf.DoCreateFieldControl(AControl, AField);
end;

function TcxFieldsTarget.GetAllowTarget(ATarget: TControl): TControl;

  function IsAllow(ACandidate: TControl): Boolean;
  begin
    Result := (csAcceptsControls in ACandidate.ControlStyle) or
      Supports(ACandidate, IcxEditorFieldLink);
  end;

begin
  Result := ATarget;
  while (Result <> nil) and not IsAllow(Result) do
    Result := Result.Parent;
end;

function TcxFieldsTarget.GetControlClass(AEditor: TFieldsEditor; AField: TField): string;
begin
  Result := cxGetControlClassName(AField);
  if Result = '' then
    Result := AEditor.DSDesigner.GetControlClass(AField);
end;

function TcxFieldsTarget.NeedCreateCaption(ATarget: TControl): Boolean;
var
  AIntf: IcxEditorFieldLink2;
begin
  Result := not Supports(ATarget, IcxEditorFieldLink2, AIntf) or AIntf.NeedCreateCaption;
end;

function TcxFieldsTarget.DragOver(Target, Source: TObject; X, Y: Integer;
  State: TDragState): Boolean;
begin
  Result := True;
end;

procedure RegisterEditRepositoryItems;
begin
  RegisterEditRepositoryItem(TcxEditRepositoryTextItem, scxSEditRepositoryTextItem);
  RegisterEditRepositoryItem(TcxEditRepositoryButtonItem, scxSEditRepositoryButtonItem);
  RegisterEditRepositoryItem(TcxEditRepositoryImageItem, scxSEditRepositoryImageItem);
  RegisterEditRepositoryItem(TcxEditRepositoryComboBoxItem, scxSEditRepositoryComboBoxItem);
  RegisterEditRepositoryItem(TcxEditRepositoryMaskItem, scxSEditRepositoryMaskItem);
  RegisterEditRepositoryItem(TcxEditRepositoryPopupItem, scxSEditRepositoryPopupItem);
  RegisterEditRepositoryItem(TcxEditRepositoryCalcItem, scxSEditRepositoryCalcItem);
  RegisterEditRepositoryItem(TcxEditRepositoryDateItem, scxSEditRepositoryDateItem);
  RegisterEditRepositoryItem(TcxEditRepositoryCurrencyItem, scxSEditRepositoryCurrencyItem);
  RegisterEditRepositoryItem(TcxEditRepositorySpinItem, scxSEditRepositorySpinItem);
  RegisterEditRepositoryItem(TcxEditRepositoryMemoItem, scxSEditRepositoryMemoItem);
  RegisterEditRepositoryItem(TcxEditRepositoryImageComboBoxItem, scxSEditRepositoryImageComboBoxItem);
  RegisterEditRepositoryItem(TcxEditRepositoryBlobItem, scxSEditRepositoryBlobItem);
  RegisterEditRepositoryItem(TcxEditRepositoryCheckBoxItem, scxSEditRepositoryCheckBoxItem);
  RegisterEditRepositoryItem(TcxEditRepositoryTimeItem, scxSEditRepositoryTimeItem);
  RegisterEditRepositoryItem(TcxEditRepositoryMRUItem, scxSEditRepositoryMRUItem);
  RegisterEditRepositoryItem(TcxEditRepositoryHyperLinkItem, scxSEditRepositoryHyperLinkItem);
  RegisterEditRepositoryItem(TcxEditRepositoryLookupComboBoxItem, scxSEditRepositoryLookupComboBoxItem);
  RegisterEditRepositoryItem(TcxEditRepositoryRadioGroupItem, scxSEditRepositoryRadioGroupItem);
end;

procedure Register;
begin
{$IFDEF DELPHI9}
  ForceDemandLoadState(dlDisable);
{$ENDIF}

  RegisterComponents(cxEditorsLibraryProductPage, [TcxTextEdit, TcxMaskEdit, TcxMemo,
    TcxDateEdit, TcxButtonEdit, TcxCheckBox, TcxComboBox, TcxImageComboBox,
    TcxSpinEdit, TcxCalcEdit, TcxHyperLinkEdit, TcxTimeEdit, TcxCurrencyEdit,
    TcxImage, TcxBlobEdit, TcxMRUEdit, TcxPopupEdit, TcxLookupComboBox,
    TcxRadioButton, TcxRadioGroup, TcxListBox, TcxNavigator, TdxBreadcrumbEdit,
    TdxColorGallery, TdxCheckGroupBox]);
  RegisterComponents(cxEditorsDBLibraryProductPage, [TcxDBTextEdit, TcxDBMaskEdit, TcxDBMemo,
    TcxDBDateEdit, TcxDBButtonEdit, TcxDBCheckBox, TcxDBComboBox, TcxDBImageComboBox,
    TcxDBSpinEdit, TcxDBCalcEdit, TcxDBHyperLinkEdit, TcxDBTimeEdit, TcxDBCurrencyEdit,
    TcxDBImage, TcxDBBlobEdit, TcxDBMRUEdit, TcxDBPopupEdit, TcxDBLookupComboBox,
    TcxDBRadioGroup, TcxDBListBox, TcxDBNavigator, TdxDBBreadcrumbEdit,
    TdxDBColorGallery, TdxDBCheckGroupBox]);
  RegisterComponents(cxEditorsUtilitiesProductPage, [TcxButton, TdxBevel, TcxGroupBox,
    TcxEditStyleController, TcxDefaultEditStyleController, TcxEditRepository,
    TcxClock, TcxScrollBox, TdxAlertWindowManager, TdxGalleryControl, TdxImageSlider]);

  RegisterClasses([TdxGalleryControlItem, TdxGalleryControlGroup]);
  RegisterNoIcon([TdxGalleryControlItem, TdxGalleryControlGroup]);

  RegisterPropertyEditor(TypeInfo(TNotifyEvent), TcxCustomEdit, 'PropertiesEvents', TcxEditPropertiesEventEditor);
  RegisterPropertyEditor(TypeInfo(TcxEditRepositoryItem), TcxCustomEdit,
    'RepositoryItem', TcxEditRepositoryItemProperty);

  RegisterPropertyEditor(TypeInfo(TColor), TcxCustomGroupBox, 'CaptionBkColor', nil);
  RegisterPropertyEditor(TypeInfo(TColor), TcxCustomGroupBox, 'Color', nil);
  RegisterPropertyEditor(TypeInfo(TFont), TcxCustomGroupBox, 'Font', nil);
{$IFDEF DELPHI16}
  RegisterPropertyEditor(TypeInfo(TDateTime), TcxCustomDateEdit, 'Date', TcxDateProperty);
{$ENDIF}
  RegisterPropertyEditor(TypeInfo(string), TcxEditDataBinding, 'DataField', TcxDataFieldProperty);
  RegisterPropertyEditor(TypeInfo(string), TcxCustomDBDataBinding, 'DataField', TcxDataFieldProperty);

  RegisterPropertyEditor(TypeInfo(string), TdxDBBreadcrumbEditDataBinding, 'ImageIndexField', TcxDataFieldProperty);
  RegisterPropertyEditor(TypeInfo(string), TdxDBBreadcrumbEditDataBinding, 'KeyField', TcxDataFieldProperty);
  RegisterPropertyEditor(TypeInfo(string), TdxDBBreadcrumbEditDataBinding, 'NameField', TcxDataFieldProperty);
  RegisterPropertyEditor(TypeInfo(string), TdxDBBreadcrumbEditDataBinding, 'ParentKeyField', TcxDataFieldProperty);

  RegisterPropertyEditor(TypeInfo(TShortCut), TcxCustomEditProperties, 'ClickKey', TShortCutProperty);
  RegisterPropertyEditor(TypeInfo(TShortCut), TcxCustomHyperLinkEditProperties, 'StartKey', TShortCutProperty);
  RegisterPropertyEditor(TypeInfo(TShortCut), TcxCustomEditProperties, 'ClearKey', TShortCutProperty);

  RegisterPropertyEditor(TypeInfo(TcxImageIndex), TcxImageComboBoxProperties, 'DefaultImageIndex', TcxGetPropertiesImageIndexProperty);
  RegisterPropertyEditor(TypeInfo(TcxImageIndex), TcxImageComboBoxItem, 'ImageIndex', TcxGetItemImageIndexProperty);
  RegisterPropertyEditor(TypeInfo(TcxImageIndex), TcxNavigatorButton, 'ImageIndex', TcxNavigatorButtonImageIndexProperty);
  RegisterPropertyEditor(TypeInfo(TcxImageIndex), TcxNavigatorCustomButton, 'ImageIndex', TcxNavigatorCustomButtonImageIndexProperty);
  RegisterPropertyEditor(TypeInfo(TcxImageIndex), TdxGalleryControlItem, 'ImageIndex', TdxGalleryControlItemImageIndexProperty);

  RegisterPropertyEditor(TypeInfo(TcxImageIndex), TcxEditButton, 'ImageIndex', TcxEditButtonImageIndexProperty);
  RegisterPropertyEditor(TypeInfo(TcxImageIndex), TcxButtonImageOptions, 'ImageIndex', TcxButtonImageIndexProperty);

  RegisterPropertyEditor(TypeInfo(TcxImageIndex), TdxAlertWindowButton, 'ImageIndex', TdxAlertWindowButtonImageIndexProperty);
  RegisterPropertyEditor(TypeInfo(TComponent), TdxAlertWindowOptionsCaptionButtons, 'PopupMenu', TcxControlPopupMenuProperty);

  RegisterPropertyEditor(TypeInfo(TcxImageIndex), TdxBreadcrumbEditButton, 'ImageIndex', TdxBreadcrumbEditButtonImageIndexProperty);
  RegisterPropertyEditor(TypeInfo(TcxImageIndex), TdxBreadcrumbEditRecentPath, 'ImageIndex', TdxBreadcrumbEditRecentPathImageIndexProperty);

  RegisterPropertyEditor(TypeInfo(string), TcxImageProperties, 'GraphicClassName', TGraphicClassNameProperty);
  RegisterPropertyEditor(TypeInfo(string), TcxImageProperties, 'Caption', TCaptionProperty);
  RegisterPropertyEditor(TypeInfo(string), TcxBlobEditProperties, 'PictureGraphicClassName', TGraphicClassNameProperty);

  RegisterComponentEditor(TcxCustomEdit, TcxEditComponentEditor);
  RegisterComponentEditor(TcxEditStyleController, TcxEditStyleControllerEditor);
  RegisterComponentEditor(TcxDefaultEditStyleController, TcxDefaultEditStyleControllerEditor);
  RegisterComponentEditor(TcxCustomButton, TcxCustomButtonComponentEditor);
  RegisterComponentEditor(TdxCustomBevel, TdxBevelComponentEditor);
  RegisterComponentEditor(TcxCustomScrollBox, TcxEditorsLibraryCXControlComponentEditor);
  RegisterComponentEditor(TcxClock, TcxEditorsLibraryCXControlComponentEditor);
  RegisterComponentEditor(TdxImageSlider, TdxSliderImageComponentEditor);
  RegisterComponentEditor(TdxAlertWindowManager, TdxAlertWindowComponentEditor);
  RegisterComponentEditor(TdxCustomBreadcrumbEdit, TcxEditorsLibraryCXControlComponentEditor);
  RegisterComponentEditor(TdxBreadcrumbEdit, TcxBreadcrumbEditComponentEditor);
  RegisterComponentEditor(TdxGalleryControl, TdxGalleryControlComponentEditor);
  RegisterComponentEditor(TdxCustomColorGallery, TcxCustomEditorsLibraryComponentEditor);

  RegisterComponentEditor(TcxEditRepository, TcxEditRepositoryComponentEditor);
  RegisterPropertyEditor(TypeInfo(TNotifyEvent), TcxEditRepositoryItem, 'PropertiesEvents', TcxEditRepositoryItemPropertiesEventEditor);
  RegisterClasses([TcxEditRepositoryItem, TcxEditRepositoryTextItem, TcxEditRepositoryButtonItem]);
  RegisterNoIcon([TcxEditRepositoryItem, TcxEditRepositoryTextItem, TcxEditRepositoryButtonItem]);

  RegisterEditRepositoryItems;

  RegisterPropertyEditor(GetPropInfo(TdxGalleryControl, 'Gallery').PropType^, TdxGalleryControl, 'Gallery', TdxGalleryPropertyEditor);

  RegisterPropertyEditor(TypeInfo(TcxEditMask), TcxCustomMaskEditProperties, 'EditMask', TcxEditMaskProperty);
  RegisterPropertyEditor(TypeInfo(TCaption), TcxCustomMaskEdit, 'Text', TcxTextProperty);

  RegisterPropertyEditor(TypeInfo(TCaption), TcxBlobEdit, 'Text', TCaptionProperty);
  RegisterPropertyEditor(TypeInfo(string), TcxLookupComboBoxProperties, 'KeyFieldNames', TcxLookupComboBoxPropertiesFieldNameProperty);
  RegisterPropertyEditor(TypeInfo(string), TcxLookupComboBoxProperties, 'ListFieldNames', TcxLookupComboBoxPropertiesFieldNameProperty);
  RegisterPropertyEditor(TypeInfo(string), TdxBreadcrumbEdit, 'SelectedPath', TdxBreadcrumbEditSelectedPathPropertyEditor);

  RegisterPropertyEditor(TypeInfo(string), TcxLookupDBGridColumn, 'FieldName', TcxLookupDBGridColumnFieldNameProperty);

  RegisterSelectionEditor(TcxControl, TcxControlSelectionEditor);
  RegisterSelectionEditor(TcxCustomEdit, TcxCustomEditSelectionEditor);
  RegisterSelectionEditor(TcxCustomButton, TcxButtonSelectionEditor);
  RegisterSelectionEditor(TdxAlertWindowManager, TdxAlertWindowManagerSelectionEditor);
  RegisterSelectionEditor(TcxDateEdit, TcxDateEditSelectionEditor);

  RegisterPropertyEditor(TypeInfo(TComponent), TcxCustomNavigatorControl,
    'Control', TcxNavigatorControlProperty);
  RegisterPropertyEditor(TypeInfo(TNotifyEvent), TcxCustomNavigator, 'ButtonsEvents', TcxNavigatorButtonsEventEditor);
  RegisterPropertyEditor(TypeInfo(TNotifyEvent), TcxCustomNavigator, 'InfoPanelEvents', TcxNavigatorInfoPanelEventEditor);
  RegisterComponentEditor(TcxRadioButton, TcxRadioButtonComponentEditor);
  RegisterComponentEditor(TcxCustomNavigator, TcxCustomNavigatorComponentEditor);
  RegisterComponentEditor(TcxContainer, TcxContainerComponentEditor);

  RegisterPropertyEditor(TypeInfo(TComponent), TcxCustomButton, 'PopupMenu', TcxControlPopupMenuProperty);
  RegisterPropertyEditor(TypeInfo(TComponent), TcxRadioButton, 'PopupMenu', TcxControlPopupMenuProperty);

  RegisterPropertyEditor(TypeInfo(TBitmap), TcxButtonImageOptions, 'Glyph', TcxBitmapProperty);
  RegisterPropertyEditor(TypeInfo(TComponent), TcxButton, 'DropDownMenu', TcxControlPopupMenuProperty);

  RegisterPropertyEditor(TypeInfo(TNotifyEvent), TcxCustomImage, 'PropertiesEvents', TcxCustomImagePropertiesProperty);
  RegisterPropertyEditor(TypeInfo(TNotifyEvent), TcxCustomBlobEdit, 'PropertiesEvents', TcxCustomImagePropertiesProperty);

  RegisterPropertyEditor(TypeInfo(TcxLookAndFeel), TcxCustomGroupBox, 'LookAndFeel', nil);
  RegisterPropertyEditor(TypeInfo(TImeMode), TcxCustomTextEdit, 'ImeMode', nil);
  RegisterPropertyEditor(TypeInfo(TImeName), TcxCustomTextEdit, 'ImeName', nil);
  RegisterPropertyEditor(TypeInfo(Boolean), TcxCustomTextEditProperties,
    'HideCursor', nil);
  RegisterPropertyEditor(TypeInfo(TcxEditRepositoryItem), TcxGroupBox,
    'RepositoryItem', nil);
  RegisterPropertyEditor(TypeInfo(Boolean), TcxCustomButton, 'UseSystemPaint', nil); // deprecated property
  RegisterPropertyEditor(TypeInfo(TcxCustomEditPropertiesValues),
    TcxCustomEditProperties, 'AssignedValues', TcxEditPropertiesAssignedValuesProperty);
  RegisterPropertyEditor(TypeInfo(TCaption), TcxCustomCheckBoxProperties, 'Caption', nil);
  RegisterPropertyEditor(TypeInfo(TcxEditStyle), TcxDefaultEditStyleController,
    '', TcxDefaultEditStyleControllerStyleProperty);
  RegisterPropertyEditor(TypeInfo(TColor), TcxHyperLinkStyle, 'TextColor', nil);
  RegisterPropertyEditor(TypeInfo(TcxEditStyle), TcxCustomGroupBox, 'StyleFocused', nil);
  RegisterPropertyEditor(TypeInfo(TcxEditStyle), TcxCustomGroupBox, 'StyleHot', nil);
  RegisterPropertyEditor(TypeInfo(string), TcxCustomNavigator, 'Hint', nil);
  RegisterPropertyEditor(TypeInfo(Boolean), TcxCustomEditProperties, 'Transparent', nil);
  RegisterPropertyEditor(TypeInfo(Boolean), TcxCustomHyperLinkEditProperties, 'AutoComplete', nil);
{$IFDEF DELPHI10}
  RegisterComponentGuidelines(TcxCustomEdit, TcxEditGuidelines);
{$ENDIF}

  HideClassProperties(TcxButton, ['AllowAllUp', 'CanBeFocused', 'Down', 'Glyph',
    'Layout', 'Margin', 'NumGlyphs', 'Spacing', 'GroupIndex', 'CommandLinkHint']);
  HideClassProperties(TcxCustomDropDownEditProperties, ['ImmediateDropDown', 'ImmediatePopup']);
  HideClassProperties(TdxGalleryControl, ['ItemShowHint', 'ItemCheckMode',
    'ColumnCount', 'ItemImageSize', 'ItemShowImageFrame', 'ItemTextPosition',
    'ContentOffset', 'ContentOffsetGroups', 'ContentOffsetItems']);
  RegisterPropertyEditor(TypeInfo(TdxDefaultBoolean), TcxDataControllerMultiThreadedOptions, 'Sorting', TdxDataControllerMultithreadedSortingPropertyEditor);
  RegisterPropertyEditor(TypeInfo(TdxDefaultBoolean), TcxDataControllerMultiThreadedOptions, 'Filtering', TdxDataControllerMultithreadedFilteringPropertyEditor);
end;

initialization
  FRegisteredDragTargets := TList.Create;
  cxRegisterDragTarget(TcxFieldsTarget);

finalization
  cxUnregisterDragTarget(TcxFieldsTarget);
  FreeAndNil(FRegisteredDragTargets);

end.
