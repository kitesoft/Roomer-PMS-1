object fraInvoiceAddressType: TfraInvoiceAddressType
  Left = 0
  Top = 0
  Width = 190
  Height = 195
  TabOrder = 0
  object rgrInvoiceAddressType: TsRadioGroup
    AlignWithMargins = True
    Left = 3
    Top = 0
    Width = 184
    Height = 195
    Margins.Top = 0
    Margins.Bottom = 0
    Align = alClient
    Caption = 'Invoice header method'
    ParentBackground = False
    TabOrder = 0
    SkinData.SkinSection = 'GROUPBOX'
    ItemIndex = 0
    Items.Strings = (
      '<auto filled>')
    OnChange = rgrInvoiceAddressTypeChange
  end
end
