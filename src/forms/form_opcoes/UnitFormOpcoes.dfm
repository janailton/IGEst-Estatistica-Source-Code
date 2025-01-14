object FormOpcoes: TFormOpcoes
  Left = 0
  Top = 0
  Caption = 'Configura'#231#245'es'
  ClientHeight = 541
  ClientWidth = 1086
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnCanResize = FormCanResize
  OnDeactivate = FormDeactivate
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1086
    Height = 481
    Align = alClient
    TabOrder = 0
    object PageControlOpcoes: TPageControl
      AlignWithMargins = True
      Left = 299
      Top = 4
      Width = 783
      Height = 473
      ActivePage = TabSheetOutrasOpcoes
      Align = alClient
      MultiLine = True
      TabOrder = 0
      object TabSheetLayou: TTabSheet
        Caption = 'Layout'
        TabVisible = False
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object GroupBox1: TGroupBox
          Left = 0
          Top = 0
          Width = 775
          Height = 463
          Align = alClient
          Caption = 'Layout'
          TabOrder = 0
          object Label1: TLabel
            Left = 24
            Top = 36
            Width = 153
            Height = 13
            Caption = 'Selecione o layout da aplica'#231#227'o:'
          end
          object Label2: TLabel
            Left = 24
            Top = 69
            Width = 181
            Height = 13
            Caption = 'Fonte da sa'#237'da do textos estat'#237'sticos:'
          end
          object Label3: TLabel
            Left = 24
            Top = 95
            Width = 137
            Height = 13
            Caption = 'Tamanho do texto da  Fonte'
          end
          object Label4: TLabel
            Left = 24
            Top = 123
            Width = 63
            Height = 13
            Caption = 'Cor da Fonte'
          end
          object ComboBoxStyle: TComboBox
            Left = 224
            Top = 33
            Width = 329
            Height = 22
            Style = csOwnerDrawFixed
            TabOrder = 0
            OnChange = ComboBoxStyleChange
          end
          object Button2: TButton
            Left = 488
            Top = 61
            Width = 65
            Height = 25
            Caption = '...'
            TabOrder = 1
            OnClick = btnSelecFont
          end
          object EditFont: TEdit
            Left = 224
            Top = 63
            Width = 258
            Height = 21
            ReadOnly = True
            TabOrder = 2
            Text = 'Arial'
            OnClick = btnSelecFont
          end
          object ComboBoxTamFont: TComboBox
            Left = 224
            Top = 92
            Width = 145
            Height = 22
            Style = csOwnerDrawFixed
            TabOrder = 3
            OnChange = ComboBoxTamFontChange
          end
          object ColorBoxFont: TColorBox
            Left = 224
            Top = 120
            Width = 145
            Height = 22
            TabOrder = 4
            OnChange = ColorBoxFontChange
          end
        end
      end
      object TabSheetPastas: TTabSheet
        Caption = 'Pastas'
        ImageIndex = 1
        TabVisible = False
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object GroupBox2: TGroupBox
          Left = 0
          Top = 0
          Width = 775
          Height = 463
          Align = alClient
          Caption = 'Pastas'
          TabOrder = 0
          object Label5: TLabel
            Left = 16
            Top = 28
            Width = 97
            Height = 13
            Align = alCustom
            Caption = 'Pasta de instala'#231#227'o:'
          end
          object Label6: TLabel
            Left = 16
            Top = 95
            Width = 175
            Height = 13
            Caption = 'Pasta dos arquivos de configura'#231#227'o:'
          end
          object Label7: TLabel
            Left = 16
            Top = 159
            Width = 139
            Height = 13
            Caption = 'Pasta de materiais de estudo'
          end
          object EditInstall: TEdit
            Left = 16
            Top = 47
            Width = 675
            Height = 21
            Align = alCustom
            ReadOnly = True
            TabOrder = 0
          end
          object EditPastaDeConfiguracao: TEdit
            Left = 16
            Top = 114
            Width = 675
            Height = 21
            Align = alCustom
            ReadOnly = True
            TabOrder = 1
          end
          object EditPastaMateriaisDeEstudo: TEdit
            Left = 16
            Top = 178
            Width = 675
            Height = 21
            Align = alCustom
            ReadOnly = True
            TabOrder = 2
          end
        end
      end
      object TabSheetOutrasOpcoes: TTabSheet
        Caption = 'Outras Op'#231#245'es'
        ImageIndex = 2
        TabVisible = False
        object GroupBox3: TGroupBox
          Left = 0
          Top = 0
          Width = 775
          Height = 463
          Align = alClient
          Caption = 'Outras Op'#231#245'es'
          TabOrder = 0
          object ValueListEditor: TValueListEditor
            Left = 2
            Top = 15
            Width = 771
            Height = 446
            Align = alClient
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSizing, goColSizing, goAlwaysShowEditor, goThumbTracking]
            TabOrder = 0
            TitleCaptions.Strings = (
              'Configura'#231#227'o'
              'Valor')
            ColWidths = (
              150
              615)
            RowHeights = (
              18
              18)
          end
        end
      end
    end
    object TabControlOpcoes: TTabControl
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 289
      Height = 473
      Align = alLeft
      TabOrder = 1
      object btnMaisOpcoes: TButton
        Left = 4
        Top = 88
        Width = 281
        Height = 41
        Align = alTop
        Caption = 'Mais Op'#231#245'es'
        TabOrder = 0
        OnClick = btnMaisOpcoesClick
      end
      object btnPastas: TButton
        Left = 4
        Top = 47
        Width = 281
        Height = 41
        Align = alTop
        Caption = 'Pastas'
        TabOrder = 1
        OnClick = btnPastasClick
      end
      object btnLayou: TButton
        Left = 4
        Top = 6
        Width = 281
        Height = 41
        Align = alTop
        Caption = 'Layout'
        TabOrder = 2
        OnClick = btnLayouClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 481
    Width = 1086
    Height = 60
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object btnSalvar: TButton
      AlignWithMargins = True
      Left = 911
      Top = 6
      Width = 175
      Height = 41
      Caption = 'Salvar'
      TabOrder = 0
      OnClick = btnSalvarClick
    end
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Left = 999
    Top = 34
  end
end
