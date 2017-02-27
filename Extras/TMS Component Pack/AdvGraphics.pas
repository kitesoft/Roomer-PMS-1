{********************************************************************}
{                                                                    }
{ written by TMS Software                                            }
{            copyright © 2016                                        }
{            Email : info@tmssoftware.com                            }
{            Web : http://www.tmssoftware.com                        }
{                                                                    }
{ The source code is given as is. The author is not responsible      }
{ for any possible damage done due to the use of this code.          }
{ The complete source code remains property of the author and may    }
{ not be distributed, published, given or sold in any form as such.  }
{ No parts of the source code can be included in any other component }
{ or application without written authorization of the author.        }
{********************************************************************}

unit AdvGraphics;

{$I TMSDEFS.INC}

{$IFDEF LCLLIB}
{$mode objfpc}{$H+}{$modeswitch advancedrecords}
{$ENDIF}

{$IFDEF FMXLIB}
{$IFDEF MSWINDOWS}
{$DEFINE FMXWINDOWS}
{$ENDIF}
{$ENDIF}

interface

uses
  {$IFDEF MSWINDOWS}
  {$IFNDEF LCLLIB}
  Windows,
  {$ENDIF}
  {$IFDEF LCLLIB}
  {$IFDEF GDIPLUSDRAWING}
  Windows,
  {$ENDIF}
  {$ENDIF}
  {$ENDIF}
  Classes, Graphics, Types
  {$IFNDEF LIMITEDGRAPHICSMODE}
  ,PictureContainer
  {$IFDEF CMNLIB}
  ,ImgList
  {$ENDIF}
  {$ENDIF}
  ,AdvTypes
  {$IFDEF FMXLIB}
  ,FMX.TextLayout
  {$ENDIF}
  {$IFNDEF LCLLIB}
  {$HINTS OFF}
  {$IF COMPILERVERSION > 22}
  ,UITypes
  {$IFEND}
  {$HINTS ON}
  ,Generics.Collections
  {$ENDIF}
  {$IFDEF LCLLIB}
  ,fgl
  {$ENDIF}
  {$IFDEF NATIVEIOSDRAWING}
  ,iOSApi.CoreGraphics, iOSApi.UIKit, iOSApi.Foundation
  ,MacApi.ObjectiveC, MacApi.CoreFoundation, MacApi.ObjcRuntime
  ,iOSApi.CocoaTypes, FMX.Canvas.GPU, FMX.Types3D, iOSApi.GLKit, iOSApi.OpenGLES
  {$ENDIF}
  {$IFDEF GDIPLUSDRAWING}
  ,AdvGDIPlusClasses, AdvGDIPlusApi
  {$ENDIF}
  ;

const
  {$IFNDEF LCLLIB}
  FPC_FULLVERSION = 0;
  {$ENDIF}
  PathScale = 1E-4;
  PathFontSize = 1E-2;
  PathPosition = 1E-3;
  PathAngle = 1E-4;

  {$IFDEF FMXLIB}
  gcAlpha = $FF000000;
  gcAliceblue = gcAlpha or $F0F8FF;
  gcAntiquewhite = gcAlpha or $FAEBD7;
  gcAqua = gcAlpha or $00FFFF;
  gcAquamarine = gcAlpha or $7FFFD4;
  gcAzure = gcAlpha or $F0FFFF;
  gcBeige = gcAlpha or $F5F5DC;
  gcBisque = gcAlpha or $FFE4C4;
  gcBlack = gcAlpha or $000000;
  gcBlanchedalmond = gcAlpha or $FFEBCD;
  gcBlue = gcAlpha or $0000FF;
  gcBlueviolet = gcAlpha or $8A2BE2;
  gcBrown = gcAlpha or $A52A2A;
  gcBurlywood = gcAlpha or $DEB887;
  gcCadetblue = gcAlpha or $5F9EA0;
  gcChartreuse = gcAlpha or $7FFF00;
  gcChocolate = gcAlpha or $D2691E;
  gcCoral = gcAlpha or $FF7F50;
  gcCornflowerblue = gcAlpha or $6495ED;
  gcCornsilk = gcAlpha or $FFF8DC;
  gcCrimson = gcAlpha or $DC143C;
  gcCyan = gcAlpha or $00FFFF;
  gcDarkblue = gcAlpha or $00008B;
  gcDarkcyan = gcAlpha or $008B8B;
  gcDarkgoldenrod = gcAlpha or $B8860B;
  gcDarkgray = gcAlpha or $A9A9A9;
  gcDarkgreen = gcAlpha or $006400;
  gcDarkgrey = gcAlpha or $A9A9A9;
  gcDarkkhaki = gcAlpha or $BDB76B;
  gcDarkmagenta = gcAlpha or $8B008B;
  gcDarkolivegreen = gcAlpha or $556B2F;
  gcDarkorange = gcAlpha or $FF8C00;
  gcDarkorchid = gcAlpha or $9932CC;
  gcDarkred = gcAlpha or $8B0000;
  gcDarksalmon = gcAlpha or $E9967A;
  gcDarkseagreen = gcAlpha or $8FBC8F;
  gcDarkslateblue = gcAlpha or $483D8B;
  gcDarkslategray = gcAlpha or $2F4F4F;
  gcDarkslategrey = gcAlpha or $2F4F4F;
  gcDarkturquoise = gcAlpha or $00CED1;
  gcDarkviolet = gcAlpha or $9400D3;
  gcDeeppink = gcAlpha or $FF1493;
  gcDeepskyblue = gcAlpha or $00BFFF;
  gcDimgray = gcAlpha or $696969;
  gcDimgrey = gcAlpha or $696969;
  gcDodgerblue = gcAlpha or $1E90FF;
  gcFirebrick = gcAlpha or $B22222;
  gcFloralwhite = gcAlpha or $FFFAF0;
  gcForestgreen = gcAlpha or $228B22;
  gcFuchsia = gcAlpha or $FF00FF;
  gcGainsboro = gcAlpha or $DCDCDC;
  gcGhostwhite = gcAlpha or $F8F8FF;
  gcGold = gcAlpha or $FFD700;
  gcGoldenrod = gcAlpha or $DAA520;
  gcGray = gcAlpha or $808080;
  gcGreen = gcAlpha or $008000;
  gcGreenyellow = gcAlpha or $ADFF2F;
  gcGrey = gcAlpha or $808080;
  gcHoneydew = gcAlpha or $F0FFF0;
  gcHotpink = gcAlpha or $FF69B4;
  gcIndianred = gcAlpha or $CD5C5C;
  gcIndigo = gcAlpha or $4B0082;
  gcIvory = gcAlpha or $FFFFF0;
  gcKhaki = gcAlpha or $F0E68C;
  gcLavender = gcAlpha or $E6E6FA;
  gcLavenderblush = gcAlpha or $FFF0F5;
  gcLawngreen = gcAlpha or $7CFC00;
  gcLemonchiffon = gcAlpha or $FFFACD;
  gcLightblue = gcAlpha or $ADD8E6;
  gcLightcoral = gcAlpha or $F08080;
  gcLightcyan = gcAlpha or $E0FFFF;
  gcLightgoldenrodyellow = gcAlpha or $FAFAD2;
  gcLightgray = gcAlpha or $D3D3D3;
  gcLightgreen = gcAlpha or $90EE90;
  gcLightgrey = gcAlpha or $D3D3D3;
  gcLightpink = gcAlpha or $FFB6C1;
  gcLightsalmon = gcAlpha or $FFA07A;
  gcLightseagreen = gcAlpha or $20B2AA;
  gcLightskyblue = gcAlpha or $87CEFA;
  gcLightslategray = gcAlpha or $778899;
  gcLightslategrey = gcAlpha or $778899;
  gcLightsteelblue = gcAlpha or $B0C4DE;
  gcLightyellow = gcAlpha or $FFFFE0;
  gcLtGray = gcAlpha or $C0C0C0;
  gcMedGray = gcAlpha or $A0A0A0;
  gcDkGray = gcAlpha or $808080;
  gcMoneyGreen = gcAlpha or $C0DCC0;
  gcLegacySkyBlue = gcAlpha or $F0CAA6;
  gcCream = gcAlpha or $F0FBFF;
  gcLime = gcAlpha or $00FF00;
  gcLimegreen = gcAlpha or $32CD32;
  gcLinen = gcAlpha or $FAF0E6;
  gcMagenta = gcAlpha or $FF00FF;
  gcMaroon = gcAlpha or $800000;
  gcMediumaquamarine = gcAlpha or $66CDAA;
  gcMediumblue = gcAlpha or $0000CD;
  gcMediumorchid = gcAlpha or $BA55D3;
  gcMediumpurple = gcAlpha or $9370DB;
  gcMediumseagreen = gcAlpha or $3CB371;
  gcMediumslateblue = gcAlpha or $7B68EE;
  gcMediumspringgreen = gcAlpha or $00FA9A;
  gcMediumturquoise = gcAlpha or $48D1CC;
  gcMediumvioletred = gcAlpha or $C71585;
  gcMidnightblue = gcAlpha or $191970;
  gcMintcream = gcAlpha or $F5FFFA;
  gcMistyrose = gcAlpha or $FFE4E1;
  gcMoccasin = gcAlpha or $FFE4B5;
  gcNavajowhite = gcAlpha or $FFDEAD;
  gcNavy = gcAlpha or $000080;
  gcOldlace = gcAlpha or $FDF5E6;
  gcOlive = gcAlpha or $808000;
  gcOlivedrab = gcAlpha or $6B8E23;
  gcOrange = gcAlpha or $FFA500;
  gcOrangered = gcAlpha or $FF4500;
  gcOrchid = gcAlpha or $DA70D6;
  gcPalegoldenrod = gcAlpha or $EEE8AA;
  gcPalegreen = gcAlpha or $98FB98;
  gcPaleturquoise = gcAlpha or $AFEEEE;
  gcPalevioletred = gcAlpha or $DB7093;
  gcPapayawhip = gcAlpha or $FFEFD5;
  gcPeachpuff = gcAlpha or $FFDAB9;
  gcPeru = gcAlpha or $CD853F;
  gcPink = gcAlpha or $FFC0CB;
  gcPlum = gcAlpha or $DDA0DD;
  gcPowderblue = gcAlpha or $B0E0E6;
  gcPurple = gcAlpha or $800080;
  gcRed = gcAlpha or $FF0000;
  gcRosybrown = gcAlpha or $BC8F8F;
  gcRoyalblue = gcAlpha or $4169E1;
  gcSaddlebrown = gcAlpha or $8B4513;
  gcSalmon = gcAlpha or $FA8072;
  gcSandybrown = gcAlpha or $F4A460;
  gcSeagreen = gcAlpha or $2E8B57;
  gcSeashell = gcAlpha or $FFF5EE;
  gcSienna = gcAlpha or $A0522D;
  gcSilver = gcAlpha or $C0C0C0;
  gcSkyblue = gcAlpha or $87CEEB;
  gcSlateblue = gcAlpha or $6A5ACD;
  gcSlategray = gcAlpha or $708090;
  gcSlategrey = gcAlpha or $708090;
  gcSnow = gcAlpha or $FFFAFA;
  gcSpringgreen = gcAlpha or $00FF7F;
  gcSteelblue = gcAlpha or $4682B4;
  gcTan = gcAlpha or $D2B48C;
  gcTeal = gcAlpha or $008080;
  gcThistle = gcAlpha or $D8BFD8;
  gcTomato = gcAlpha or $FF6347;
  gcTurquoise = gcAlpha or $40E0D0;
  gcViolet = gcAlpha or $EE82EE;
  gcWheat = gcAlpha or $F5DEB3;
  gcWhite = gcAlpha or $FFFFFF;
  gcWhitesmoke = gcAlpha or $F5F5F5;
  gcYellow = gcAlpha or $FFFF00;
  gcYellowgreen = gcAlpha or $9ACD32;
  gcNull = $00000000;
  {$ENDIF}
  {$IFDEF CMNLIB}
  gcAliceblue = $FFF8F0;
  gcAntiquewhite = $D7EBFA;
  gcAqua = $FFFF00;
  gcAquamarine = $D4FF7F;
  gcAzure = $FFFFF0;
  gcBeige = $DCF5F5;
  gcBisque = $C4E4FF;
  gcBlack = $000000;
  gcBlanchedalmond = $CDEBFF;
  gcBlue = $FF0000;
  gcBlueviolet = $E22B8A;
  gcBrown = $2A2AA5;
  gcBurlywood = $87B8DE;
  gcCadetblue = $A09E5F;
  gcChartreuse = $00FF7F;
  gcChocolate = $1E69D2;
  gcCoral = $507FFF;
  gcCornflowerblue = $ED9564;
  gcCornsilk = $DCF8FF;
  gcCrimson = $3C14DC;
  gcCyan = $FFFF00;
  gcDarkblue = $8B0000;
  gcDarkcyan = $8B8B00;
  gcDarkgoldenrod = $0B86B8;
  gcDarkgray = $A9A9A9;
  gcDarkgreen = $006400;
  gcDarkgrey = $A9A9A9;
  gcDarkkhaki = $6BB7BD;
  gcDarkmagenta = $8B008B;
  gcDarkolivegreen = $2F6B55;
  gcDarkorange = $008CFF;
  gcDarkorchid = $CC3299;
  gcDarkred = $00008B;
  gcDarksalmon = $7A96E9;
  gcDarkseagreen = $8FBC8F;
  gcDarkslateblue = $8B3D48;
  gcDarkslategray = $4F4F2F;
  gcDarkslategrey = $4F4F2F;
  gcDarkturquoise = $D1CE00;
  gcDarkviolet = $D30094;
  gcDeeppink = $9314FF;
  gcDeepskyblue = $FFBF00;
  gcDimgray = $696969;
  gcDimgrey = $696969;
  gcDodgerblue = $FF901E;
  gcFirebrick = $2222B2;
  gcFloralwhite = $F0FAFF;
  gcForestgreen = $228B22;
  gcFuchsia = $FF00FF;
  gcGainsboro = $DCDCDC;
  gcGhostwhite = $FFF8F8;
  gcGold = $00D7FF;
  gcGoldenrod = $20A5DA;
  gcGray = $808080;
  gcGreen = $008000;
  gcGreenyellow = $2FFFAD;
  gcGrey = $808080;
  gcHoneydew = $F0FFF0;
  gcHotpink = $B469FF;
  gcIndianred = $5C5CCD;
  gcIndigo = $82004B;
  gcIvory = $F0FFFF;
  gcKhaki = $8CE6F0;
  gcLavender = $FAE6E6;
  gcLavenderblush = $F5F0FF;
  gcLawngreen = $00FC7C;
  gcLemonchiffon = $CDFAFF;
  gcLightblue = $E6D8AD;
  gcLightcoral = $8080F0;
  gcLightcyan = $FFFFE0;
  gcLightgoldenrodyellow = $D2FAFA;
  gcLightgray = $D3D3D3;
  gcLightgreen = $90EE90;
  gcLightgrey = $D3D3D3;
  gcLightpink = $C1B6FF;
  gcLightsalmon = $7AA0FF;
  gcLightseagreen = $AAB220;
  gcLightskyblue = $FACE87;
  gcLightslategray = $998877;
  gcLightslategrey = $998877;
  gcLightsteelblue = $DEC4B0;
  gcLightyellow = $E0FFFF;
  gcLtGray = $C0C0C0;
  gcMedGray = $A4A0A0;
  gcDkGray = $808080;
  gcMoneyGreen = $C0DCC0;
  gcLegacySkyBlue = $F0CAA6;
  gcCream = $F0FBFF;
  gcLime = $00FF00;
  gcLimegreen = $32CD32;
  gcLinen = $E6F0FA;
  gcMagenta = $FF00FF;
  gcMaroon = $000080;
  gcMediumaquamarine = $AACD66;
  gcMediumblue = $CD0000;
  gcMediumorchid = $D355BA;
  gcMediumpurple = $DB7093;
  gcMediumseagreen = $71B33C;
  gcMediumslateblue = $EE687B;
  gcMediumspringgreen = $9AFA00;
  gcMediumturquoise = $CCD148;
  gcMediumvioletred = $8515C7;
  gcMidnightblue = $701919;
  gcMintcream = $FAFFF5;
  gcMistyrose = $E1E4FF;
  gcMoccasin = $B5E4FF;
  gcNavajowhite = $ADDEFF;
  gcNavy = $800000;
  gcOldlace = $E6F5FD;
  gcOlive = $008080;
  gcOlivedrab = $238E6B;
  gcOrange = $00A5FF;
  gcOrangered = $0045FF;
  gcOrchid = $D670DA;
  gcPalegoldenrod = $AAE8EE;
  gcPalegreen = $98FB98;
  gcPaleturquoise = $EEEEAF;
  gcPalevioletred = $9370DB;
  gcPapayawhip = $D5EFFF;
  gcPeachpuff = $B9DAFF;
  gcPeru = $3F85CD;
  gcPink = $CBC0FF;
  gcPlum = $DDA0DD;
  gcPowderblue = $E6E0B0;
  gcPurple = $800080;
  gcRed = $0000FF;
  gcRosybrown = $8F8FBC;
  gcRoyalblue = $E16941;
  gcSaddlebrown = $13458B;
  gcSalmon = $7280FA;
  gcSandybrown = $60A4F4;
  gcSeagreen = $578B2E;
  gcSeashell = $EEF5FF;
  gcSienna = $2D52A0;
  gcSilver = $C0C0C0;
  gcSkyblue = $EBCE87;
  gcSlateblue = $CD5A6A;
  gcSlategray = $908070;
  gcSlategrey = $908070;
  gcSnow = $FAFAFF;
  gcSpringgreen = $7FFF00;
  gcSteelblue = $B48246;
  gcTan = $8CB4D2;
  gcTeal = $808000;
  gcThistle = $D8BFD8;
  gcTomato = $4763FF;
  gcTurquoise = $D0E040;
  gcViolet = $EE82EE;
  gcWheat = $B3DEF5;
  gcWhite = $FFFFFF;
  gcWhitesmoke = $F5F5F5;
  gcYellow = $00FFFF;
  gcYellowgreen = $32CD9A;
  gcNull = -1;
  {$ENDIF}

type
  {$IFDEF FMXLIB}
  TAdvGraphicsColor = TAlphaColor;
  {$ENDIF}
  {$IFDEF CMNLIB}
  TAdvGraphicsColor = TColor;
  {$ENDIF}

  TAdvGraphicsColorEntry = record
    Value: TAdvGraphicsColor;
    Name: PChar;
  end;

const
  AdvGraphicsColorCount = 154;
  AdvGraphicsColors: array[0..AdvGraphicsColorCount - 1] of TAdvGraphicsColorEntry = (
  (Value: gcAliceblue; Name:'gcAliceblue'),
  (Value: gcAntiquewhite; Name:'gcAntiquewhite'),
  (Value: gcAqua; Name:'gcAqua'),
  (Value: gcAquamarine; Name:'gcAquamarine'),
  (Value: gcAzure; Name:'gcAzure'),
  (Value: gcBeige; Name:'gcBeige'),
  (Value: gcBisque; Name:'gcBisque'),
  (Value: gcBlack; Name:'gcBlack'),
  (Value: gcBlanchedalmond; Name:'gcBlanchedalmond'),
  (Value: gcBlue; Name:'gcBlue'),
  (Value: gcBlueviolet; Name:'gcBlueviolet'),
  (Value: gcBrown; Name:'gcBrown'),
  (Value: gcBurlywood; Name:'gcBurlywood'),
  (Value: gcCadetblue; Name:'gcCadetblue'),
  (Value: gcChartreuse; Name:'gcChartreuse'),
  (Value: gcChocolate; Name:'gcChocolate'),
  (Value: gcCoral; Name:'gcCoral'),
  (Value: gcCornflowerblue; Name:'gcCornflowerblue'),
  (Value: gcCornsilk; Name:'gcCornsilk'),
  (Value: gcCrimson; Name:'gcCrimson'),
  (Value: gcCyan; Name:'gcCyan'),
  (Value: gcDarkblue; Name:'gcDarkblue'),
  (Value: gcDarkcyan; Name:'gcDarkcyan'),
  (Value: gcDarkgoldenrod; Name:'gcDarkgoldenrod'),
  (Value: gcDarkgray; Name:'gcDarkgray'),
  (Value: gcDarkgreen; Name:'gcDarkgreen'),
  (Value: gcDarkgrey; Name:'gcDarkgrey'),
  (Value: gcDarkkhaki; Name:'gcDarkkhaki'),
  (Value: gcDarkmagenta; Name:'gcDarkmagenta'),
  (Value: gcDarkolivegreen; Name:'gcDarkolivegreen'),
  (Value: gcDarkorange; Name:'gcDarkorange'),
  (Value: gcDarkorchid; Name:'gcDarkorchid'),
  (Value: gcDarkred; Name:'gcDarkred'),
  (Value: gcDarksalmon; Name:'gcDarksalmon'),
  (Value: gcDarkseagreen; Name:'gcDarkseagreen'),
  (Value: gcDarkslateblue; Name:'gcDarkslateblue'),
  (Value: gcDarkslategray; Name:'gcDarkslategray'),
  (Value: gcDarkslategrey; Name:'gcDarkslategrey'),
  (Value: gcDarkturquoise; Name:'gcDarkturquoise'),
  (Value: gcDarkviolet; Name:'gcDarkviolet'),
  (Value: gcDeeppink; Name:'gcDeeppink'),
  (Value: gcDeepskyblue; Name:'gcDeepskyblue'),
  (Value: gcDimgray; Name:'gcDimgray'),
  (Value: gcDimgrey; Name:'gcDimgray'),
  (Value: gcDodgerblue; Name:'gcDodgerblue'),
  (Value: gcFirebrick; Name:'gcFirebrick'),
  (Value: gcFloralwhite; Name:'gcFloralwhite'),
  (Value: gcForestgreen; Name:'gcForestgreen'),
  (Value: gcFuchsia; Name:'gcFuchsia'),
  (Value: gcGainsboro; Name:'gcGainsboro'),
  (Value: gcGhostwhite; Name:'gcGhostwhite'),
  (Value: gcGold; Name:'gcGold'),
  (Value: gcGoldenrod; Name:'gcGoldenrod'),
  (Value: gcGray; Name:'gcGray'),
  (Value: gcGreen; Name:'gcGreen'),
  (Value: gcGreenyellow; Name:'gcGreenyellow'),
  (Value: gcGrey; Name:'gcGrey'),
  (Value: gcHoneydew; Name:'gcHoneydew'),
  (Value: gcHotpink; Name:'gcHotpink'),
  (Value: gcIndianred; Name:'gcIndianred'),
  (Value: gcIndigo; Name:'gcIndigo'),
  (Value: gcIvory; Name:'gcIvory'),
  (Value: gcKhaki; Name:'gcKhaki'),
  (Value: gcLavender; Name:'gcLavender'),
  (Value: gcLavenderblush; Name:'gcLavenderblush'),
  (Value: gcLawngreen; Name:'gcLawngreen'),
  (Value: gcLemonchiffon; Name:'gcLemonchiffon'),
  (Value: gcLightblue; Name:'gcLightblue'),
  (Value: gcLightcoral; Name:'gcLightcoral'),
  (Value: gcLightcyan; Name:'gcLightcyan'),
  (Value: gcLightgoldenrodyellow; Name:'gcLightgoldenrodyellow'),
  (Value: gcLightgray; Name:'gcLightgray'),
  (Value: gcLightgreen; Name:'gcLightgreen'),
  (Value: gcLightgrey; Name:'gcLightgrey'),
  (Value: gcLightpink; Name:'gcLightpink'),
  (Value: gcLightsalmon; Name:'gcLightsalmon'),
  (Value: gcLightseagreen; Name:'gcLightseagreen'),
  (Value: gcLightskyblue; Name:'gcLightskyblue'),
  (Value: gcLightslategray; Name:'gcLightslategray'),
  (Value: gcLightslategrey; Name:'gcLightslategrey'),
  (Value: gcLightsteelblue; Name:'gcLightsteelblue'),
  (Value: gcLightyellow; Name:'gcLightyellow'),
  (Value: gcLtGray; Name:'gcLtGray'),
  (Value: gcMedGray; Name:'gcMedGray'),
  (Value: gcDkGray; Name:'gcDkGray'),
  (Value: gcMoneyGreen; Name:'gcMoneyGreen'),
  (Value: gcLegacySkyBlue; Name:'gcLegacySkyBlue'),
  (Value: gcCream; Name:'gcCream'),
  (Value: gcLime; Name:'gcLime'),
  (Value: gcLimegreen; Name:'gcLimegreen'),
  (Value: gcLinen; Name:'gcLinen'),
  (Value: gcMagenta; Name:'gcMagenta'),
  (Value: gcMaroon; Name:'gcMaroon'),
  (Value: gcMediumaquamarine; Name:'gcMediumaquamarine'),
  (Value: gcMediumblue; Name:'gcMediumblue'),
  (Value: gcMediumorchid; Name:'gcMediumorchid'),
  (Value: gcMediumpurple; Name:'gcMediumpurple'),
  (Value: gcMediumseagreen; Name:'gcMediumseagreen'),
  (Value: gcMediumslateblue; Name:'gcMediumslateblue'),
  (Value: gcMediumspringgreen; Name:'gcMediumspringgreen'),
  (Value: gcMediumturquoise; Name:'gcMediumturquoise'),
  (Value: gcMediumvioletred; Name:'gcMediumvioletred'),
  (Value: gcMidnightblue; Name:'gcMidnightblue'),
  (Value: gcMintcream; Name:'gcMintcream'),
  (Value: gcMistyrose; Name:'gcMistyrose'),
  (Value: gcMoccasin; Name:'gcMoccasin'),
  (Value: gcNavajowhite; Name:'gcNavajowhite'),
  (Value: gcNavy; Name:'gcNavy'),
  (Value: gcOldlace; Name:'gcOldlace'),
  (Value: gcOlive; Name:'gcOlive'),
  (Value: gcOlivedrab; Name:'gcOlivedrab'),
  (Value: gcOrange; Name:'gcOrange'),
  (Value: gcOrangered; Name:'gcOrangered'),
  (Value: gcOrchid; Name:'gcOrchid'),
  (Value: gcPalegoldenrod; Name:'gcPalegoldenrod'),
  (Value: gcPalegreen; Name:'gcPalegreen'),
  (Value: gcPaleturquoise; Name:'gcPaleturquoise'),
  (Value: gcPalevioletred; Name:'gcPalevioletred'),
  (Value: gcPapayawhip; Name:'gcPapayawhip'),
  (Value: gcPeachpuff; Name:'gcPeachpuff'),
  (Value: gcPeru; Name:'gcPeru'),
  (Value: gcPink; Name:'gcPink'),
  (Value: gcPlum; Name:'gcPlum'),
  (Value: gcPowderblue; Name:'gcPowderblue'),
  (Value: gcPurple; Name:'gcPurple'),
  (Value: gcRed; Name:'gcRed'),
  (Value: gcRosybrown; Name:'gcRosybrown'),
  (Value: gcRoyalblue; Name:'gcRoyalblue'),
  (Value: gcSaddlebrown; Name:'gcSaddlebrown'),
  (Value: gcSalmon; Name:'gcSalmon'),
  (Value: gcSandybrown; Name:'gcSandybrown'),
  (Value: gcSeagreen; Name:'gcSeagreen'),
  (Value: gcSeashell; Name:'gcSeashell'),
  (Value: gcSienna; Name:'gcSienna'),
  (Value: gcSilver; Name:'gcSilver'),
  (Value: gcSkyblue; Name:'gcSkyblue'),
  (Value: gcSlateblue; Name:'gcSlateblue'),
  (Value: gcSlategray; Name:'gcSlategray'),
  (Value: gcSlategrey; Name:'gcSlategrey'),
  (Value: gcSnow; Name:'gcSnow'),
  (Value: gcSpringgreen; Name:'gcSpringgreen'),
  (Value: gcSteelblue; Name:'gcSteelblue'),
  (Value: gcTan; Name:'gcTan'),
  (Value: gcTeal; Name:'gcTeal'),
  (Value: gcThistle; Name:'gcThistle'),
  (Value: gcTomato; Name:'gcTomato'),
  (Value: gcTurquoise; Name:'gcTurquoise'),
  (Value: gcViolet; Name:'gcViolet'),
  (Value: gcWheat; Name:'gcWheat'),
  (Value: gcWhite; Name:'gcWhite'),
  (Value: gcWhitesmoke; Name:'gcWhitesmoke'),
  (Value: gcYellow; Name:'gcYellow'),
  (Value: gcYellowgreen; Name:'gcYellowgreen'),
  (Value: gcNull; Name:'gcNull'));

type
  TAdvGraphicsStrokeKind = (gskNone, gskSolid, gskDash, gskDot, gskDashDot, gskDashDotDot);
  TAdvGraphicsFillKind = (gfkNone, gfkSolid, gfkGradient);
  TAdvGraphicsFillOrientation = (gfoHorizontal, gfoVertical);
  TAdvGraphicsTextAlign = (gtaCenter, gtaLeading, gtaTrailing);
  TAdvGraphicsTextTrimming = (gttNone, gttCharacter, gttWord);
  TAdvGraphicsSide = (gsLeft, gsTop, gsRight, gsBottom);
  TAdvGraphicsSides = set of TAdvGraphicsSide;

const
  AllSides = [gsLeft, gsTop, gsRight, gsBottom];

type
  TAdvGraphicsStroke = class;
  TAdvGraphicsFill = class;
  TAdvGraphicsFont = class;

  TAdvGraphicsSaveState = class(TPersistent)
  private
    FFont: TAdvGraphicsFont;
    FStroke: TAdvGraphicsStroke;
    FFill: TAdvGraphicsFill;
    {$IFDEF CMNLIB}
    FSaveDC: Integer;
    {$ENDIF}
    {$IFDEF FMXLIB}
    FSaveDC: TCanvasSaveState;
    {$ENDIF}
    procedure SetStroke(const Value: TAdvGraphicsStroke);
    procedure SetFill(const Value: TAdvGraphicsFill);
    procedure SetFont(const Value: TAdvGraphicsFont);
  public
    constructor Create;
    destructor Destroy; override;
    property Stroke: TAdvGraphicsStroke read FStroke write SetStroke;
    property Fill: TAdvGraphicsFill read FFill write SetFill;
    property Font: TAdvGraphicsFont read FFont write SetFont;
    {$IFDEF CMNLIB}
    property SaveDC: Integer read FSaveDC write FSaveDC;
    {$ENDIF}
    {$IFDEF FMXLIB}
    property SaveDC: TCanvasSaveState read FSaveDC write FSaveDC;
    {$ENDIF}
  end;

  TAdvGraphics = class;

  IAdvGraphicsExport = interface
    ['{481CA803-8B50-4545-B212-57AC0D065D09}']
    procedure &Export({%H-}AGraphics: TAdvGraphics; {%H-}ARect: TRectF);
  end;

  TAdvCustomGraphicsFill = class(TPersistent)
  private
    FOnChanged: TNotifyEvent;
    FOrientation: TAdvGraphicsFillOrientation;
    FKind: TAdvGraphicsFillKind;
    FColor: TAdvGraphicsColor;
    FColorTo: TAdvGraphicsColor;
    FColorMirror: TAdvGraphicsColor;
    FColorMirrorTo: TAdvGraphicsColor;
    {$IFDEF FMXLIB}
    FOpacity: Single;
    {$ENDIF}
    procedure SetKind(const Value: TAdvGraphicsFillKind);
    procedure SetOrientation(const Value: TAdvGraphicsFillOrientation);
    procedure SetColor(const Value: TAdvGraphicsColor);
    procedure SetColorTo(const Value: TAdvGraphicsColor);
    procedure SetColorMirror(const Value: TAdvGraphicsColor);
    procedure SetColorMirrorTo(const Value: TAdvGraphicsColor);
    {$IFDEF FMXLIB}
    procedure SetOpacity(const Value: Single);
    function IsOpacityStored: Boolean;
    {$ENDIF}
  protected
    procedure Changed;
    property OnChanged: TNotifyEvent read FOnChanged write FOnChanged;
    property Kind: TAdvGraphicsFillKind read FKind write SetKind default gfkSolid;
    property Orientation: TAdvGraphicsFillOrientation read FOrientation write SetOrientation default gfoVertical;
    property Color: TAdvGraphicsColor read FColor write SetColor default gcWhite;
    property ColorTo: TAdvGraphicsColor read FColorTo write SetColorTo default gcGray;
    property ColorMirror: TAdvGraphicsColor read FColorMirror write SetColorMirror default gcNull;
    property ColorMirrorTo: TAdvGraphicsColor read FColorMirrorTo write SetColorMirrorTo default gcNull;
    {$IFDEF FMXLIB}
    property Opacity: Single read FOpacity write SetOpacity stored IsOpacityStored nodefault;
    {$ENDIF}
  public
    constructor Create(const AKind: TAdvGraphicsFillKind = gfkSolid; const AColor: TAdvGraphicsColor = gcWhite); virtual;
    procedure Assign(Source: TPersistent); override;
  end;

  TAdvGraphicsFill = class(TAdvCustomGraphicsFill)
  published
    property OnChanged;
    property Kind;
    property Orientation;
    property Color;
    property ColorTo;
    property ColorMirror;
    property ColorMirrorTo;
    {$IFDEF FMXLIB}
    property Opacity;
    {$ENDIF}
  end;

  TAdvGraphicsFont = class(TFont)
  private
  {$IFDEF CMNLIB}
    FOnChanged: TNotifyEvent;
  {$ENDIF}
  {$IFDEF FMXLIB}
    FColor: TAdvGraphicsColor;
    procedure SetColor(const Value: TAdvGraphicsColor);
    procedure SetName(const Value: string);
    function GetName: string;
  {$ENDIF}
  {$IFDEF CMNLIB}
  protected
    procedure DoChanged(Sender: TObject);
    {$IFDEF LCLLIB}
    procedure Changed; override;
    {$ENDIF}
  {$ENDIF}
  public
  {$IFNDEF LCLLIB}
    constructor Create; virtual;
  {$ENDIF}
  {$IFDEF LCLLIB}
    constructor Create; override;
  {$ENDIF}
    procedure Assign(Source: TPersistent); override;
  {$IFDEF FMXLIB}
  published
    property Color: TAdvGraphicsColor read FColor write SetColor default gcBlack;
    property Name: string read GetName write SetName;
  {$ENDIF}
  {$IFDEF CMNLIB}
    property OnChanged: TNotifyEvent read FOnChanged write FOnChanged;
  {$ENDIF}
  end;

  TAdvCustomGraphicsStroke = class(TPersistent)
  private
    FOnChanged: TNotifyEvent;
    FKind: TAdvGraphicsStrokeKind;
    FColor: TAdvGraphicsColor;
    FWidth: Single;
    {$IFDEF FMXLIB}
    FOpacity: Single;
    {$ENDIF}
    procedure SetKind(const Value: TAdvGraphicsStrokeKind);
    procedure SetColor(const Value: TAdvGraphicsColor);
    procedure SetWidth(const Value: Single);
    {$IFDEF FMXLIB}
    procedure SetOpacity(const Value: Single);
    function IsOpacityStored: Boolean;
    {$ENDIF}
    function IsWidthStored: Boolean;
  protected
    procedure Changed;
    property OnChanged: TNotifyEvent read FOnChanged write FOnChanged;
    property Kind: TAdvGraphicsStrokeKind read FKind write SetKind default gskSolid;
    property Color: TAdvGraphicsColor read FColor write SetColor default gcSilver;
    property Width: Single read FWidth write SetWidth stored IsWidthStored nodefault;
    {$IFDEF FMXLIB}
    property Opacity: Single read FOpacity write SetOpacity stored IsOpacityStored nodefault;
    {$ENDIF}
  public
    constructor Create(const AKind: TAdvGraphicsStrokeKind = gskSolid; const AColor: TAdvGraphicsColor = gcSilver); virtual;
    procedure Assign(Source: TPersistent); override;
  end;

  TAdvGraphicsStroke = class(TAdvCustomGraphicsStroke)
  published
    property OnChanged;
    property Kind;
    property Color;
    property Width;
    {$IFDEF FMXLIB}
    property Opacity;
    {$ENDIF}
  end;

  TAdvGraphicsPathPolygon = array of TPointF;

  TAdvGraphicsPathPointKind = (gppMoveTo, gppLineTo, gppCurveTo, gppClose);

  TAdvGraphicsPathCubicBezier = array [0..3] of TPointF;

  TAdvGraphicsPathPoint = record
    Kind: TAdvGraphicsPathPointKind;
    {$HINTS OFF}
    {$WARNINGS OFF}
    {$IF FPC_FULLVERSION < 30000}
    Dummy: Boolean;
    {$IFEND}
    {$HINTS ON}
    {$WARNINGS ON}
    Point: TPointF;
    {$IFDEF LCLLIB}
    class operator = (z1, z2 : TAdvGraphicsPathPoint) b : Boolean;
    {$ENDIF}
  end;

  TAdvGraphicsPathDrawMode = (pdmPolygon, pdmPolyline);

  TAdvGraphicsPathPoints = class(TList<TAdvGraphicsPathPoint>);

  TAdvGraphicsPath = class(TPersistent)
  private
    FStartPoint: TPointF;
    FPoints: TAdvGraphicsPathPoints;
    procedure CalculateBezierCoefficients(const Bezier: TAdvGraphicsPathCubicBezier; out AX, BX, CX, AY, BY, CY: Single);
    function PointOnBezier(const StartPoint: TPointF; const AX, BX, CX, AY, BY, CY, T: Single): TPointF;
    function CreateBezier(const Bezier: TAdvGraphicsPathCubicBezier; const PointCount: Integer): TAdvGraphicsPathPolygon;
    function GetCount: Integer;
    function GetPoint(AIndex: Integer): TAdvGraphicsPathPoint;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    function LastPoint: TPointF;
    procedure MoveTo(const P: TPointF);
    procedure LineTo(const P: TPointF);
    procedure CurveTo(const ControlPoint1, ControlPoint2, EndPoint: TPointF);
    procedure SmoothCurveTo(const ControlPoint2, EndPoint: TPointF);
    procedure QuadCurveTo(const ControlPoint, EndPoint: TPointF);
    procedure ClosePath;
    procedure AddEllipse(const ARect: TRectF);
    procedure AddRectangle(const ARect: TRectF);
    procedure AddArc(const Center, Radius: TPointF; StartAngle, SweepAngle: Single);
    procedure AddPath(APath: TAdvGraphicsPath);
    procedure Clear;
    procedure Flatten(const Flatness: Single = 0.25);
    procedure FlattenToPolygon(var Polygon: TAdvGraphicsPathPolygon; const Flatness: Single = 0.25);
    property Count: Integer read GetCount;
    property Points[AIndex: Integer]: TAdvGraphicsPathPoint read GetPoint; default;
    property PathData: TAdvGraphicsPathPoints read FPoints;
  end;

  TAdvGraphicsModifyRectMode = (gcrmNone, gcrmExpandAll, gcrmShrinkAll, gcrmShiftRightAndExpandHeight, gcrmShiftDownAndExpandWidth,
    gcrmShiftRightAndShrinkHeight, gcrmShiftRightDown, gcrmShiftRightUp, gcrmShiftLeftUp, gcrmShiftLeftDown, gcrmShiftUpAndExpandWidth,
    gcrmShiftLeftAndExpandHeight);
  TAdvGraphicsModifyPointMode = (gcpmNone, gcpmLeftUp, gcpmRightDown, gcpmLeftDown, gcpmRightUp);
  TAdvGraphicsExpanderState = (gesCollapsed, gesExpanded);
  TAdvGraphicsCompactState = (gcsCollapsed, gcsExpanded);

  TAdvGraphicsCorner = (gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight);
  TAdvGraphicsCorners = set of TAdvGraphicsCorner;

  TAdvGraphics = class
  private
    {$IFDEF NATIVEIOSDRAWING}
    FContext: CGContextRef;
    FContextGradient: CGGradientRef;
    {$ENDIF}
    FBlockUpdate: Boolean;
    FCanvas: TCanvas;
    {$IFDEF GDIPLUSDRAWING}
    FGDIPCanvas: TGPGraphics;
    {$ENDIF}
    FBitmap: TBitmap;
    FFill: TAdvGraphicsFill;
    FStroke: TAdvGraphicsStroke;
    FFont: TAdvGraphicsFont;
    {$IFDEF FMXLIB}
    FTextLayout: TTextLayout;
    {$ENDIF}
    {$IFNDEF LIMITEDGRAPHICSMODE}
    FHighlightColor: TAdvGraphicsColor;
    FHighlightTextColor: TAdvGraphicsColor;
    FHighlightFontStyles: TFontStyles;
    FURLUnderline: Boolean;
    FURLColor: TAdvGraphicsColor;
    FPictureContainer: TPictureContainer;
    {$IFDEF CMNLIB}
    FImageList: TCustomImageList;
    {$ENDIF}
    {$ENDIF}
    {$IFNDEF GDIPLUSDRAWING}
    {$IFDEF CMNLIB}
    FOldPenHandle: THandle;
    {$ENDIF}
    {$ENDIF}
  protected
    procedure FontChanged(Sender: TObject);
    procedure FillChanged(Sender: TObject);
    procedure StrokeChanged(Sender: TObject);
    {$IFDEF CMNLIB}
    procedure DrawRotatedText(ACanvas: TCanvas; ARect: TRect; AText: String; AAngle: Single; AHorizontalAlign, AVerticalAlign: TAdvGraphicsTextAlign);
    {$ENDIF}
    procedure InitializeDefaultAppearance;
    class procedure ConvertBitmapToGrayScale(ABitmap: TAdvBitmap);
  public class var
    DefaultSelectionFillColor: TAdvGraphicsColor;
    DefaultTextFontColor: TAdvGraphicsColor;
    DefaultPopupFillColor: TAdvGraphicsColor;
    DefaultPopupStrokeColor: TAdvGraphicsColor;
    DefaultButtonStrokeColorFocused: TAdvGraphicsColor;
    DefaultButtonFillColorFocused: TAdvGraphicsColor;
    DefaultButtonStrokeColorDisabled: TAdvGraphicsColor;
    DefaultButtonFillColorDisabled: TAdvGraphicsColor;
    DefaultButtonStrokeColor: TAdvGraphicsColor;
    DefaultButtonFillColor: TAdvGraphicsColor;
  public
    constructor Create(ACanvas: TCanvas); virtual;
    constructor CreateBitmapCanvas(AWidth: Integer = 1; AHeight: Integer = 1); virtual;
    destructor Destroy; override;
    procedure StartSpecialPen;
    procedure StopSpecialPen;
    procedure BeginScene; virtual;
    procedure EndScene; virtual;
    procedure SetFill(AFill: TAdvGraphicsFill); virtual;
    procedure SetStroke(AStroke: TAdvGraphicsStroke); virtual;
    procedure RestoreState(AState: TAdvGraphicsSaveState; ACanvasOnly: Boolean = False); virtual;
    procedure SetFillKind(AKind: TAdvGraphicsFillKind); virtual;
    procedure SetFillColor(AColor: TAdvGraphicsColor); virtual;
    procedure SetFontColor(AColor: TAdvGraphicsColor); virtual;
    procedure SetFontName(AName: string); virtual;
    procedure SetFont(AFont: TAdvGraphicsFont); virtual;
    procedure SetFontSize(ASize: Integer); virtual;
    procedure SetFontStyles(AStyle: TFontStyles); virtual;
    procedure SetStrokeKind(AKind: TAdvGraphicsStrokeKind); virtual;
    procedure SetStrokeColor(AColor: TAdvGraphicsColor); virtual;
    procedure SetStrokeWidth(AWidth: Single); virtual;
    procedure DrawLine(AFromPoint: TPoint; AToPoint: TPoint; {%H-}AModifyPointModeFrom: TAdvGraphicsModifyPointMode = gcpmRightDown; {%H-}AModifyPointModeTo: TAdvGraphicsModifyPointMode = gcpmRightDown); overload; virtual;
    procedure DrawLine(AFromPoint: TPointF; AToPoint: TPointF; {%H-}AModifyPointModeFrom: TAdvGraphicsModifyPointMode = gcpmRightDown; {%H-}AModifyPointModeTo: TAdvGraphicsModifyPointMode = gcpmRightDown); overload; virtual;
    procedure DrawFocusRectangle(ALeft, ATop, ARight, ABottom: Integer; AColor: TAdvGraphicsColor = gcBlack; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawFocusRectangle(ARect: TRect; AColor: TAdvGraphicsColor = gcBlack; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawFocusRectangle(ALeft, ATop, ARight, ABottom: Double; AColor: TAdvGraphicsColor = gcBlack; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawFocusRectangle(ARect: TRectF; AColor: TAdvGraphicsColor = gcBlack; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawFocusPath(APath: TAdvGraphicsPath; AColor: TAdvGraphicsColor = gcBlack); virtual;
    procedure DrawPolygon(APolygon: TAdvGraphicsPathPolygon); virtual;
    procedure DrawPolyline(APolyline: TAdvGraphicsPathPolygon); virtual;
    procedure DrawPath(APath: TAdvGraphicsPath; APathMode: TAdvGraphicsPathDrawMode = pdmPolygon); virtual;
    procedure DrawArc(const Center, Radius: TPointF; StartAngle, SweepAngle: Single); overload; virtual;
    procedure DrawArc(const Center, Radius: TPoint; StartAngle, SweepAngle: Integer); overload; virtual;
    procedure DrawRectangle(ALeft, ATop, ARight, ABottom: Double; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRectangle(ALeft, ATop, ARight, ABottom: Double; ASides: TAdvGraphicsSides; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawEllipse(ALeft, ATop, ARight, ABottom: Double; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRectangle(ARect: TRectF; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRectangle(ARect: TRectF; ASides: TAdvGraphicsSides; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRectangle(ALeft, ATop, ARight, ABottom: Integer; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRectangle(ALeft, ATop, ARight, ABottom: Integer; ASides: TAdvGraphicsSides; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawEllipse(ALeft, ATop, ARight, ABottom: Integer; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRectangle(ARect: TRect; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRectangle(ARect: TRect; ASides: TAdvGraphicsSides; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRoundRectangle(ALeft, ATop, ARight, ABottom: Double; ARounding: Single = 10; ACorners: TAdvGraphicsCorners = [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight]; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRoundRectangle(ARect: TRectF; ARounding: Single = 10; ACorners: TAdvGraphicsCorners = [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight]; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRoundRectangle(ALeft, ATop, ARight, ABottom: Integer; ARounding: Integer = 10; ACorners: TAdvGraphicsCorners = [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight]; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawRoundRectangle(ARect: TRect; ARounding: Integer = 10; ACorners: TAdvGraphicsCorners = [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight]; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawEllipse(ARect: TRectF; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawBitmapPart(ASourceLeft, ASourceTop, ASourceRight, ASourceBottom: Double; ADestinationLeft, ADestinationTop, ADestinationRight, ADestinationBottom: Double;
    ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawBitmapPart(ASourceRect: TRectF; ADestinationRect: TRectF; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawBitmap(ALeft, ATop, ARight, ABottom: Double; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawBitmap(ARect: TRectF; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawEllipse(ARect: TRect; {%H-}AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll); overload; virtual;
    procedure DrawBitmapPart(ASourceLeft, ASourceTop, ASourceRight, ASourceBottom: Integer; ADestinationLeft, ADestinationTop, ADestinationRight, ADestinationBottom: Integer;
    ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawBitmapPart(ASourceRect: TRect; ADestinationRect: TRect; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawBitmap(ALeft, ATop, ARight, ABottom: Integer; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawBitmap(ARect: TRect; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawBitmap(ALeft, ATop: Integer; ABitmap: TAdvDrawBitmap); overload; virtual;
    procedure DrawBitmap(ALeft, ATop: Single; ABitmap: TAdvDrawBitmap); overload; virtual;
    {$IFDEF CMNLIB}
    procedure DrawBitmap(ALeft, ATop: Integer; ABitmap: TAdvBitmap); overload; virtual;
    procedure DrawBitmap(ALeft, ATop: Single; ABitmap: TAdvBitmap); overload; virtual;
    {$ENDIF}
    procedure DrawCheckBox(ARect: TRectF; AChecked: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True); overload; virtual;
    procedure DrawButton(ARect: TRectF; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True); overload; virtual;
    procedure DrawCloseButton(ARect: TRectF; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True); overload; virtual;
    procedure DrawExpanderButton(ARect: TRectF; AState: TAdvGraphicsExpanderState = gesExpanded; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True); overload; virtual;
    procedure DrawCompactButton(ARect: TRectF; AState: TAdvGraphicsCompactState = gcsExpanded; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True); overload; virtual;
    procedure DrawDropDownButton(ARect: TRectF; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; ACenter: Boolean = False; AAdaptToStyle: Boolean = True); overload; virtual;
    procedure DrawRadioButton(ARect: TRectF; AChecked: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True); overload; virtual;
    procedure DrawProgressBar(ARect: TRectF; AValue: Single; AFormat: string = '%.0f%%'; AMax: Single = 100; AColor: TAdvGraphicsColor = gcYellowgreen; ATextColor: TAdvGraphicsColor = gcBlack; AShowText: Boolean = True; AEnabled: Boolean = True); overload; virtual;
    procedure DrawCheckBox(ARect: TRect; AChecked: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True); overload; virtual;
    procedure DrawButton(ARect: TRect; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True); overload; virtual;
    procedure DrawCloseButton(ARect: TRect; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True); overload; virtual;
    procedure DrawExpanderButton(ARect: TRect; AState: TAdvGraphicsExpanderState = gesExpanded; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True); overload; virtual;
    procedure DrawCompactButton(ARect: TRect; AState: TAdvGraphicsCompactState = gcsExpanded; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True); overload; virtual;
    procedure DrawDropDownButton(ARect: TRect; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; ACenter: Boolean = False; AAdaptToStyle: Boolean = True); overload; virtual;
    procedure DrawRadioButton(ARect: TRect; AChecked: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True); overload; virtual;
    procedure DrawProgressBar(ARect: TRect; AValue: Single; AFormat: string = '%.0f%%'; AMax: Single = 100; AColor: TAdvGraphicsColor = gcYellowgreen; ATextColor: TAdvGraphicsColor = gcBlack; AShowText: Boolean = True; AEnabled: Boolean = True); overload; virtual;
    {$IFNDEF LIMITEDGRAPHICSMODE}
    procedure DrawBitmapWithName(ALeft, ATop, ARight, ABottom: Double; ABitmapName: string; AApplyScale: Boolean = False; AScale: Single = 0; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawBitmapWithName(ARect: TRectF; ABitmapName: string; AApplyScale: Boolean = False; AScale: Single = 0; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawScaledBitmap(ARect: TRectF; ABitmaps: TAdvScaledBitmaps; AScale: Single = 0; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawScaledBitmap(ALeft, ATop, ARight, ABottom: Double; ABitmaps: TAdvScaledBitmaps; AScale: Single = 0; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawBitmapWithName(ALeft, ATop, ARight, ABottom: Integer; ABitmapName: string; AApplyScale: Boolean = False; AScale: Single = 0; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawBitmapWithName(ARect: TRect; ABitmapName: string; AApplyScale: Boolean = False; AScale: Single = 0; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawScaledBitmap(ARect: TRect; ABitmaps: TAdvScaledBitmaps; AScale: Single = 0; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    procedure DrawScaledBitmap(ALeft, ATop, ARight, ABottom: Integer; ABitmaps: TAdvScaledBitmaps; AScale: Single = 0; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False); overload; virtual;
    {$ENDIF}
    function GetBitmapDrawRectangle(ALeft, ATop, ARight, ABottom: Double; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False): TRectF; overload; virtual;
    function GetBitmapDrawRectangle(ARect: TRectF; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False): TRectF; overload; virtual;
    function GetBitmapDrawRectangle(ALeft, ATop, ARight, ABottom: Integer; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False): TRect; overload; virtual;
    function GetBitmapDrawRectangle(ARect: TRect; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False): TRect; overload; virtual;
    procedure ClipRect(ARect: TRectF); overload; virtual;
    function CalculateTextSize(AText: string; ARect: TRectF; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): TSizeF; overload; virtual;
    function CalculateTextWidth(AText: string; ARect: TRectF; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): Single; overload; virtual;
    function CalculateTextHeight(AText: string; ARect: TRectF; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): Single; overload; virtual;
    function CalculateText(AText: String; ARect: TRectF; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): TRectF; overload; virtual;
    function CalculateTextSize(AText: string): TSizeF; overload; virtual;
    function CalculateTextWidth(AText: string): Single; overload; virtual;
    function CalculateTextHeight(AText: string): Single; overload; virtual;
    function CalculateText(AText: String): TRectF; overload; virtual;
    procedure ClipRect(ARect: TRect); overload; virtual;
    function CalculateTextSize(AText: string; ARect: TRect; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): TSize; overload; virtual;
    function CalculateTextWidth(AText: string; ARect: TRect; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): Integer; overload; virtual;
    function CalculateTextHeight(AText: string; ARect: TRect; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): Integer; overload; virtual;
    function CalculateText(AText: String; ARect: TRect; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): TRect; overload; virtual;
    function CalculateTextSizeInt(AText: string): TSize; overload; virtual;
    function CalculateTextWidthInt(AText: string): Integer; overload; virtual;
    function CalculateTextHeightInt(AText: string): Integer; overload; virtual;
    function CalculateTextInt(AText: String): TRect; overload; virtual;
    {$IFDEF FMXWINDOWS}
    function CalculateTextWin(AText: string; ARect: TRectF; AWordWrapping: Boolean): TRectF; virtual;
    {$ENDIF}
    function DrawText(ARect: TRectF; AText: String; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading; AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
      AMinWidth: Single = -1; AMinHeight: Single = -1 {$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String; overload; virtual;
    function DrawText(ALeft, ATop, ARight, ABottom: Double; AText: String; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading; AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
      AMinWidth: Single = -1; AMinHeight: Single = -1 {$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String; overload; virtual;
    function DrawText(ARect: TRect; AText: String; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading; AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
      AMinWidth: Single = -1; AMinHeight: Single = -1 {$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String; overload; virtual;
    function DrawText(ALeft, ATop, ARight, ABottom: Integer; AText: String; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading; AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
      AMinWidth: Single = -1; AMinHeight: Single = -1 {$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String; overload; virtual;
    function DrawText(ARect: TRectF; AText: String; var AControlID: String; var AControlValue: String; var AControlType: string;AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading; AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
      AMinWidth: Single = -1; AMinHeight: Single = -1 {$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String; overload; virtual;
    function DrawText(ALeft, ATop, ARight, ABottom: Double; AText: String; var AControlID: String; var AControlValue: String; var AControlType: string; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading; AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
      AMinWidth: Single = -1; AMinHeight: Single = -1 {$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String; overload; virtual;
    function DrawText(ARect: TRect; AText: String; var AControlID: String; var AControlValue: String; var AControlType: string; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading; AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
      AMinWidth: Single = -1; AMinHeight: Single = -1 {$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String; overload; virtual;
    function DrawText(ALeft, ATop, ARight, ABottom: Integer; AText: String; var AControlID: String; var AControlValue: String; var AControlType: string; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading; AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
      AMinWidth: Single = -1; AMinHeight: Single = -1 {$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String; overload; virtual;
    function SaveState(ACanvasOnly: Boolean = False): TAdvGraphicsSaveState; virtual;
    property Fill: TAdvGraphicsFill read FFill;
    property Stroke: TAdvGraphicsStroke read FStroke;
    property Font: TAdvGraphicsFont read FFont;
    {$IFDEF GDIPLUSDRAWING}
    property GDIPCanvas: TGPGraphics read FGDIPCanvas;
    {$ENDIF}
    property Canvas: TCanvas read FCanvas;
    property Bitmap: TBitmap read FBitmap;
    {$IFNDEF LIMITEDGRAPHICSMODE}
    property HighlightColor: TAdvGraphicsColor read FHighlightColor write FHighlightColor;
    property HighlightTextColor: TAdvGraphicsColor read FHighlightTextColor write FHighlightTextColor;
    property HighlightFontStyle: TFontStyles read FHighlightFontStyles write FHighlightFontStyles;
    {$IFDEF CMNLIB}
    property ImageList: TCustomImageList read FImageList write FImageList;
    {$ENDIF}
    property PictureContainer: TPictureContainer read FPictureContainer write FPictureContainer;
    property URLColor: TAdvGraphicsColor read FURLColor write FURLColor default gcBlue;
    property URLUnderline: Boolean read FURLUnderline write FURLUnderline default True;
    class function ApplyHilight(AText, AHilight, ATag: string; ADoCase: Boolean): string;
    class function GetBitmapFromPictureContainer(APictureContainer: TPictureContainer; AName: string; AApplyScale: Boolean = False; AScale: Single = 0): TAdvBitmap; virtual;
    class function GetScaledBitmap(ABitmaps: TAdvScaledBitmaps; AScale: Single = 0; APictureContainer: TPictureContainer = nil): TAdvBitmap;
    {$ENDIF}
    class procedure GetAspectSize(var AWidth: Single; var AHeight: Single; AOriginalWidth: Single; AOriginalHeight: Single; ANewWidth: Single; ANewHeight: Single; AAspectRatio: Boolean = True;
      AStretch: Boolean = False; ACropping: Boolean = False); virtual;
    class procedure DrawSample(ACanvas: TCanvas; ARect: TRectF); virtual;
    class function PointInPath(APoint: TPointF; APath: TAdvGraphicsPath): Boolean; overload; virtual;
    class function PointInPath(APoint: TPoint; APath: TAdvGraphicsPath): Boolean; overload; virtual;
    class function PointInPolygon(APoint: TPointF; APolygon: TAdvGraphicsPathPolygon): Boolean; overload; virtual;
    class function PointInPolygon(APoint: TPoint; APolygon: TAdvGraphicsPathPolygon): Boolean; overload; virtual;
    class function PointInRect(APoint: TPointF; ARect: TRectF): Boolean; overload; virtual;
    class function PointInRect(APoint: TPoint; ARect: TRect): Boolean; overload; virtual;
    class function GetColorRed(AColor: TAdvGraphicsColor): Byte; virtual;
    class function GetColorGreen(AColor: TAdvGraphicsColor): Byte; virtual;
    class function GetColorBlue(AColor: TAdvGraphicsColor): Byte; virtual;
    {$IFDEF FMXLIB}
    class function GetColorAlpha(AColor: TAdvGraphicsColor): Byte; virtual;
    {$ENDIF}
    class function ColorToHTML(AColor: TAdvGraphicsColor): string; virtual;
    class function HTMLToColor(AHTML: string): TAdvGraphicsColor; virtual;
    class function TextToColor(AText: string): TAdvGraphicsColor; virtual;
  end;

{$IFDEF NATIVEIOSDRAWING}
type
  NSStringDrawingContext = interface(NSObject)
  end;

  NSStringClass = interface(NSObjectClass)
    ['{41873934-4A7E-4E99-9934-7B7CB5952BCE}']
    {class} function stringWithCharacters(characters: MarshaledString; length: NSUInteger): Pointer; cdecl;
  end;
  NSString = interface(NSObject)
    ['{8033A0C8-4240-4CEC-98A2-1D17C8BC8FE6}']
    function cString: MarshaledAString; cdecl;
    function sizeWithFont(font: UIFont; forWidth: CGFloat; lineBreakMode: NSLineBreakMode): CGSize; cdecl; overload;
    function sizeWithFont(font: UIFont): CGSize; cdecl; overload;
    function drawAtPoint(aPoint: NSPoint; withFont: UIFont): CGSize; cdecl; overload;
    procedure drawAtPoint(aPoint: NSPoint; withAttributes: NSDictionary); cdecl; overload;
    procedure drawInRect(aRect: NSRect; withAttributes: NSDictionary); cdecl; overload;
    function drawInRect(aRect: NSRect; withFont: UIFont): CGSize; cdecl; overload;
    function drawInRect(aRect: NSRect; withFont: UIFont; lineBreakMode: NSLineBreakMode; alignment: NSTextAlignment): CGSize; cdecl; overload;
    function sizeWithAttributes(aAttributes: NSDictionary): NSSize; cdecl;
    function boundingRectWithSize(size: CGSize; options: NSStringDrawingOptions; attributes: NSDictionary; context: NSStringDrawingContext): CGRect; cdecl;
  end;
  TNSString = class(TOCGenericImport<NSStringClass, NSString>)  end;
{$ENDIF}

function ModifyRect(const ARect: TRectF; const {%H-}ARectMode: TAdvGraphicsModifyRectMode): TRectF;
function ModifyPoint(const APoint: TPointF; const {%H-}APointMode: TAdvGraphicsModifyPointMode): TPointF;
function MakeGraphicsColor(ARed, AGreen, ABlue: Byte{$IFDEF FMXLIB};AAlpha: Byte = 255{$ENDIF}): TAdvGraphicsColor;
function Lighter(AColor: TAdvGraphicsColor; APercent: Byte): TAdvGraphicsColor;
function Darker(AColor: TAdvGraphicsColor; APercent: Byte): TAdvGraphicsColor;
function Blend(AColor1: TAdvGraphicsColor; AColor2: TAdvGraphicsColor; ALevel: Byte): TAdvGraphicsColor;
{$IFDEF NATIVEIOSDRAWING}
function AlphaColorToUIColor(AColor: TAdvGraphicsColor): UIColor;
function UIColorToAlphaColor(AColor: UIColor): TAdvGraphicsColor;
{$ENDIF}
function ColorLookup: TStringList;

implementation

{$IFNDEF LIMITEDGRAPHICSMODE}
{$R AdvGraphics.res}
{$ENDIF}

uses
  {$IFDEF FMXLIB}
  UIConsts, System.Math.Vectors, FMX.Types,
  {$ENDIF}
  {$IFDEF LCLLIB}
  LCLType, LCLIntF,
  {$ENDIF}
  {$IFNDEF LIMITEDGRAPHICSMODE}
  AdvGraphicsHTMLEngine, AdvUtils,
  {$ENDIF}
  SysUtils, Math

  {$IFDEF GDIPLUSDRAWING}
  ,ActiveX
  {$ENDIF}
  {$IFDEF FMXWINDOWS}
  ,WinApi.D2D1, WinApi.D3D10, WinApi.Dxgi,WinApi.DxgiFormat,
  WinApi.ActiveX, FMX.Canvas.D2D, Winapi.D3D10_1,
  FMX.Consts
  {$ENDIF}
  ;

var
  FColorLookup: TStringList;

type
  TAdvGraphicsColorObject = class
  private
    FColor: TAdvGraphicsColor;
  public
    constructor Create(AColor: TAdvGraphicsColor);
    property Color: TAdvGraphicsColor read FColor write FColor;
  end;

function ColorLookup: TStringList;
begin
  Result := FColorLookup;
end;

{$IFDEF FMXWINDOWS}
type
  TDirect3DLevel = (lUndetermined, lUnsupported, lDirect3D10, lDirect3D10_1);
  TDirect3DSupport = (sUndetermined, sDirect3D10Legacy, sDirect3D10, sDirect3D10_1);

var
  FSharedDevice: ID3D10Device;
  FSharedDXGIFactory: IDXGIFactory;
  FSharedFactory: ID2D1Factory;
  FSharedDWriteFactory: IDWriteFactory;
  FDirect3DLevel: TDirect3DLevel;
  FDirect3DSupport: TDirect3DSupport;
  FDirect3DHardware: Boolean;
{$ENDIF}


function MathRound(AValue: Extended): Int64;
begin
  if AValue >= 0 then
    Result := Trunc(AValue + 0.5)
  else
    Result := Trunc(AValue - 0.5);
end;

{$IFDEF NATIVEIOSDRAWING}
function AlphaColorToUIColor(AColor: TAlphaColor): UIColor;
var
  R: CGFloat;
  G: CGFloat;
  B: CGFloat;
  A: CGFloat;
begin
  if AColor = TAlphaColorRec.Null then
  begin
    Result := TUIColor.Wrap(TUIColor.OCClass.clearColor);
    Exit;
  end;

  A := TAlphaColorRec(AColor).A / 255;
  R := TAlphaColorRec(AColor).R / 255;
  G := TAlphaColorRec(AColor).G / 255;
  B := TAlphaColorRec(AColor).B / 255;
  Result := TUIColor.Wrap(TUIColor.OCClass.colorWithRed(R, G, B, A));
end;

function UIColorToAlphaColor(AColor: UIColor): TAlphaColor;
var
  r, g, b, a: CGFloat;
begin
  if AColor = TUIColor.Wrap(TUIColor.OCClass.clearColor) then
  begin
    Result := TAlphaColorRec.Null;
    Exit;
  end;

  AColor.getRed(@r, @g, @b, @a);

  TAlphaColorRec(Result).R := Round(r * 255);
  TAlphaColorRec(Result).g := Round(g * 255);
  TAlphaColorRec(Result).b := Round(b * 255);
  TAlphaColorRec(Result).a := Round(a * 255);
end;
{$ENDIF}

{$IFDEF GDIPLUSDRAWING}
function ConvertToGDIPColor(AColor: TAdvGraphicsColor): Cardinal;
begin
  Result := MakeColor(TAdvGraphics.GetColorRed(AColor), TAdvGraphics.GetColorGreen(AColor), TAdvGraphics.GetColorBlue(AColor));
end;

function CreateGDIPStroke(AStroke: TAdvGraphicsStroke): TGPPen;
begin
  Result := TGPPen.Create(ConvertToGDIPColor(AStroke.Color), AStroke.Width);
  case AStroke.Kind of
    gskSolid: Result.SetDashStyle(DashStyleSolid);
    gskDash: Result.SetDashStyle(DashStyleDash);
    gskDot: Result.SetDashStyle(DashStyleDot);
    gskDashDot: Result.SetDashStyle(DashStyleDashDot);
    gskDashDotDot: Result.SetDashStyle(DashStyleDashDotDot);
  end;
end;

function CreateGDIPFill(AFill: TAdvGraphicsFill; ARect: TGPRectF): TGPBrush;
begin
  Result := nil;
  case AFill.Kind of
    gfkSolid: Result := TGPSolidBrush.Create(ConvertToGDIPColor(AFill.Color));
    gfkGradient:
    begin
      case AFill.Orientation of
        gfoHorizontal: Result := TGPLinearGradientBrush.Create(ARect, ConvertToGDIPColor(AFill.Color), ConvertToGDIPColor(AFill.ColorTo), LinearGradientModeHorizontal);
        gfoVertical: Result := TGPLinearGradientBrush.Create(ARect, ConvertToGDIPColor(AFill.Color), ConvertToGDIPColor(AFill.ColorTo), LinearGradientModeVertical);
      end;
    end;
  end;
end;

function CreateGDIPFontFill(AFont: TAdvGraphicsFont): TGPBrush;
begin
  Result := TGPSolidBrush.Create(ConvertToGDIPColor(AFont.Color));
end;

function CreateGPStringFormat(AHAlign: TAdvGraphicsTextAlign; AVAlign: TAdvGraphicsTextAlign; AWrap: Boolean): TGPStringFormat;
var
  flags: integer;
begin
  Result := TGPStringFormat.Create;
  case AHAlign of
    gtaLeading:
      Result.SetAlignment(StringAlignmentNear);
    gtaTrailing:
      Result.SetAlignment(StringAlignmentFar);
    gtaCenter:
      Result.SetAlignment(StringAlignmentCenter);
  end;
  case AValign of
    gtaLeading:
      Result.SetLineAlignment(StringAlignmentNear);
    gtaTrailing:
      Result.SetLineAlignment(StringAlignmentFar);
    gtaCenter:
      Result.SetLineAlignment(StringAlignmentCenter);
  end;
  flags := StringFormatFlagsNoClip;
  if not AWrap then
    flags := flags or StringFormatFlagsNoWrap;
  Result.SetFormatFlags(flags);
end;

function CreateGDIPFont(AFont: TAdvGraphicsFont): TGPFont;
var
  style: integer;
begin
  style := FontStyleRegular;
  if fsBold in AFont.Style then
    style := style + FontStyleBold;
  if fsItalic in AFont.Style then
    style := style + FontStyleItalic;
  if fsUnderline in AFont.Style then
    style := style + FontStyleUnderline;
  if fsStrikeOut in AFont.Style then
    style := style + FontStyleStrikeout;
  result := TGPFont.Create(AFont.Name, AFont.Size, style, UnitPoint);
end;

function PolyToGDIPPoints(APolyLine: TAdvGraphicsPathPolygon): TPointFDynArray;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for I := 0 to Length(APolyLine) - 1 do
  begin
    SetLength(Result, Length(Result) + 1);
    Result[Length(Result) - 1] := MakePoint(APolyLine[I].X, APolyLine[I].Y);
  end;
end;

function PolyToGDIPRect(APolyLine: TAdvGraphicsPathPolygon): TGPRectF;
var
  I: Integer;
  pt: TPointF;
  r: TRectF;
begin
  r := RectF(-1, -1, -1, -1);
  for I := 0 to Length(APolyLine) - 1 do
  begin
    pt := APolyline[I];
    if (pt.X < r.Left) or (r.Left = -1) then
      r.Left := pt.X;

    if (pt.Y < r.Top) or (r.Top = -1) then
      r.Top := pt.Y;

    if (pt.X > r.Right) or (r.Right = -1) then
      r.Right := pt.X;

    if (pt.Y > r.Bottom) or (r.Bottom = -1) then
      r.Bottom := pt.Y;
  end;

  Result := MakeRect(r.Left, r.Top, r.Width, r.Height);
end;
{$ENDIF}

function MulDiv(nNumber, nNumerator, nDenominator: Integer): Integer;
begin
  if nDenominator = 0 then
    Result := -1
  else
    Result := MathRound(Int64(nNumber) * Int64(nNumerator) / nDenominator);
end;

function Blend(AColor1: TAdvGraphicsColor; AColor2: TAdvGraphicsColor; ALevel: Byte): TAdvGraphicsColor;
var
  c1, c2: LongInt;
  r, g, b, v1, v2: byte;
begin
  ALevel := Round(2.55 * ALevel);
  {$IFDEF CMNLIB}
  c1 := ColorToRGB(AColor1);
  c2 := ColorToRGB(AColor2);
  {$ENDIF}
  {$IFDEF FMXLIB}
  c1 := AColor1;
  c2 := AColor2;
  {$ENDIF}
  v1 := Byte(c1);
  v2 := Byte(c2);
  r := Max(0, Min(255, ALevel * (v1 - v2) shr 8 + v2));
  v1 := Byte(c1 shr 8);
  v2 := Byte(c2 shr 8);
  g := Max(0, Min(255, ALevel * (v1 - v2) shr 8 + v2));
  v1 := Byte(c1 shr 16);
  v2 := Byte(c2 shr 16);
  b := Max(0, Min(255, ALevel * (v1 - v2) shr 8 + v2));
  {$IFDEF CMNLIB}
  Result := (b shl 16) + (g shl 8) + r;
  {$ENDIF}
  {$IFDEF FMXLIB}
  Result := MakeGraphicsColor(r, g, b);
  {$ENDIF}
end;

function Lighter(AColor: TAdvGraphicsColor; APercent: Byte): TAdvGraphicsColor;
var
  r, g, b: Byte;
begin
  {$IFDEF CMNLIB}
  AColor := ColorToRGB(AColor);
  r := GetRValue(AColor);
  g := GetGValue(AColor);
  b := GetBValue(AColor);
  {$ENDIF}
  {$IFDEF FMXLIB}
  r := TAlphaColorRec(AColor).R;
  g := TAlphaColorRec(AColor).G;
  b := TAlphaColorRec(AColor).B;
  {$ENDIF}

  r := r + MulDiv(255 - r, APercent, 100);
  g := g + MulDiv(255 - g, APercent, 100);
  b := b + MulDiv(255 - b, APercent, 100);

  {$IFDEF FMXLIB}
  Result := MakeGraphicsColor(r, g, b, TAlphaColorRec(AColor).A);
  {$ENDIF}

  {$IFDEF CMNLIB}
  Result := MakeGraphicsColor(r, g, b);
  {$ENDIF}
end;

function Darker(AColor: TAdvGraphicsColor; APercent: Byte): TAdvGraphicsColor;
var
  r, g, b: Byte;
begin
  {$IFDEF CMNLIB}
  AColor := ColorToRGB(AColor);
  r := GetRValue(AColor);
  g := GetGValue(AColor);
  b := GetBValue(AColor);
  {$ENDIF}
  {$IFDEF FMXLIB}
  r := TAlphaColorRec(AColor).R;
  g := TAlphaColorRec(AColor).G;
  b := TAlphaColorRec(AColor).B;
  {$ENDIF}

  r := r - MulDiv(255 - r, APercent, 100);
  g := g - MulDiv(255 - g, APercent, 100);
  b := b - MulDiv(255 - b, APercent, 100);

  {$IFDEF FMXLIB}
  Result := MakeGraphicsColor(r, g, b, TAlphaColorRec(AColor).A);
  {$ENDIF}

  {$IFDEF CMNLIB}
  Result := MakeGraphicsColor(r, g, b);
  {$ENDIF}
end;

{$IFDEF CMNLIB}
procedure DrawGradient(ACanvas: TCanvas; AColor, AColorTo: TColor;
  ARect: TRect; ARounding: Single; ACorners: TAdvGraphicsCorners; ADirection: Boolean);
var
  diffr,startr,endr: Integer;
  diffg,startg,endg: Integer;
  diffb,startb,endb: Integer;
  iend, si: Integer;
  rstepr,rstepg,rstepb,rstepw: Double;
  i,stepw: Word;
  oldp, oldb: TColor;
  Steps: Integer;
  R, dr: TRect;
  a: Single;
begin
  R := ARect;

  if ADirection then
    Steps := R.Right - R.Left
  else
    Steps := R.Bottom - R.Top;

  if Steps = 0 then
    Steps := 1;

  AColor := ColorToRGB(AColor);
  AColorTo := ColorToRGB(AColorTo);

  startr := (AColor and $0000FF);
  startg := (AColor and $00FF00) shr 8;
  startb := (AColor and $FF0000) shr 16;

  endr := (AColorTo and $0000FF);
  endg := (AColorTo and $00FF00) shr 8;
  endb := (AColorTo and $FF0000) shr 16;

  diffr := endr - startr;
  diffg := endg - startg;
  diffb := endb - startb;

  rstepr := diffr / steps;
  rstepg := diffg / steps;
  rstepb := diffb / steps;

  if ADirection then
    rstepw := (R.Right - R.Left) / Steps
  else
    rstepw := (R.Bottom - R.Top) / Steps;

  with ACanvas do
  begin
    oldb := Brush.Color;
    oldp := Pen.Color;
    for i := 0 to Steps - 1 do
    begin
      endr := startr + Round(rstepr*i);
      endg := startg + Round(rstepg*i);
      endb := startb + Round(rstepb*i);
      stepw := Round(i*rstepw);
      Pen.Color := endr + (endg shl 8) + (endb shl 16);
      Brush.Color := Pen.Color;

      if ADirection then
      begin
        si := Trunc(rstepw);
        iend := R.Left + stepw + si;
        iend := Min(iend, R.Right);

        dr := r;

        if (I <= ARounding) and ((gcTopLeft in ACorners) or (gcBottomLeft in ACorners)) then
        begin
          a := SQRT(Power(ARounding, 2) - Power(ARounding - I, 2));

          if (gcTopLeft in ACorners) then
            dr.Top := dr.Top + Round(ARounding - a);

          if (gcBottomLeft in ACorners) then
            dr.Bottom := dr.Bottom - Round(ARounding - a);
        end
        else if (I >= Steps - ARounding) and ((gcBottomRight in ACorners) or (gcTopRight in ACorners)) then
        begin
          a := SQRT(Power(ARounding, 2) - Power(ARounding - (Steps - I), 2));

          if (gcTopRight in ACorners) then
            dr.Top := dr.Top + Round(ARounding - a);

          if (gcBottomRight in ACorners) then
            dr.Bottom := dr.Bottom - Round(ARounding - a);
        end;

        Rectangle(dr.Left + stepw, dr.Top, iend, dr.Bottom)
      end
      else
      begin
        si := Trunc(rstepw);
        iend := R.Top + stepw + si;
        iend := Min(iend, r.Bottom);

        dr := r;

        if (I <= ARounding) and ((gcTopLeft in ACorners) or (gcTopRight in ACorners)) then
        begin
          a := SQRT(Power(ARounding, 2) - Power(ARounding - I, 2));

          if (gcTopLeft in ACorners) then
            dr.Left := dr.Left + Round(ARounding - a);

          if (gcTopRight in ACorners) then
            dr.Right := dr.Right - Round(ARounding - a);
        end
        else if (I >= Steps - ARounding) and ((gcBottomLeft in ACorners) or (gcBottomRight in ACorners)) then
        begin
          a := SQRT(Power(ARounding, 2) - Power(ARounding - (Steps - I), 2));

          if (gcBottomLeft in ACorners) then
            dr.Left := dr.Left + Round(ARounding - a);

          if (gcBottomRight in ACorners) then
            dr.Right := dr.Right - Round(ARounding - a);
        end;

        Rectangle(dr.Left, dr.Top + stepw, dr.Right, iend);
      end;
    end;
    Pen.Color := oldp;
    Brush.Color := oldb;
  end;
end;
{$ENDIF}

function MakeGraphicsColor(ARed, AGreen, ABlue: Byte{$IFDEF FMXLIB};AAlpha: Byte = 255{$ENDIF}): TAdvGraphicsColor;
begin
  {$IFDEF FMXLIB}
  Result := MakeColor(ARed, AGreen, ABlue, AAlpha);
  {$ENDIF}
  {$IFDEF VCLLIB}
  Result := RGB(ARed, AGreen, ABlue);
  {$ENDIF}
  {$IFDEF LCLLIB}
  Result := RGBToColor(ARed, AGreen, ABlue);
  {$ENDIF}
end;

procedure TAdvGraphics.EndScene;
begin
  {$IFDEF FMXLIB}
  if Assigned(FCanvas) then
    FCanvas.EndScene;
  {$ENDIF}
end;

procedure TAdvGraphics.BeginScene;
begin
  {$IFDEF FMXLIB}
  if Assigned(FCanvas) then
  begin
    FCanvas.BeginScene;
    FCanvas.Clear(gcNull);
  end;
  {$ENDIF}
end;

constructor TAdvGraphics.CreateBitmapCanvas(AWidth: Integer = 1; AHeight: Integer = 1);
begin
  FBitmap := TBitmap.Create{$IFDEF FMXLIB}(AWidth, AHeight){$ENDIF};
  FBitmap.Width := AWidth;
  FBitmap.Height := AHeight;
  FCanvas := FBitmap.Canvas;
  {$IFDEF GDIPLUSDRAWING}
  FGDIPCanvas := TGPGraphics.Create(FCanvas.Handle);
  FGDIPCanvas.SetSmoothingMode(SmoothingModeAntiAlias);
  FGDIPCanvas.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
  {$ENDIF}
  FFill := TAdvGraphicsFill.Create;
  FFill.OnChanged := FillChanged;
  FStroke := TAdvGraphicsStroke.Create;
  FStroke.OnChanged := StrokeChanged;
  FFont := TAdvGraphicsFont.Create;
  FFont.OnChanged := FontChanged;
  InitializeDefaultAppearance;
end;

constructor TAdvGraphics.Create(ACanvas: TCanvas);
begin
  {$IFDEF NATIVEIOSDRAWING}
  FContext := UIGraphicsGetCurrentContext;
  UIGraphicsPushContext(FContext);
  {$ENDIF}
  FCanvas := ACanvas;
  {$IFDEF GDIPLUSDRAWING}
  FGDIPCanvas := TGPGraphics.Create(FCanvas.Handle);
  FGDIPCanvas.SetSmoothingMode(SmoothingModeAntiAlias);
  FGDIPCanvas.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
  {$ENDIF}
  FFill := TAdvGraphicsFill.Create;
  FFill.OnChanged := FillChanged;
  FStroke := TAdvGraphicsStroke.Create;
  FStroke.OnChanged := StrokeChanged;
  FFont := TAdvGraphicsFont.Create;
  FFont.OnChanged := FontChanged;
  {$IFNDEF LIMITEDGRAPHICSMODE}
  FHighlightColor := gcBlue;
  FHighlightTextColor := gcWhite;
  FHighlightFontStyles := [];
  {$eNDIF}
  InitializeDefaultAppearance;
end;

procedure TAdvGraphics.RestoreState(AState: TAdvGraphicsSaveState; ACanvasOnly: Boolean = False);
begin
  if not ACanvasOnly then
  begin
    SetFill(AState.Fill);
    SetStroke(AState.Stroke);
    SetFont(AState.Font);
  end;

  {$IFDEF NATIVEIOSDRAWING}
  CGContextRestoreGState(FContext);
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  FGDIPCanvas.ResetClip;
  FGDIPCanvas.Restore(AState.SaveDC);
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  {$IFDEF VCLLIB}
  RestoreDC(FCanvas.Handle, AState.SaveDC);
  {$ENDIF}
  {$IFDEF LCLLIB}
  FCanvas.Clipping := False;
  FCanvas.RestoreHandleState;
  {$ENDIF}
  {$ENDIF}
  AState.SaveDC := 0;
  {$ENDIF}
  {$IFDEF FMXLIB}
  FCanvas.RestoreState(AState.SaveDC);
  AState.SaveDC := nil;
  {$ENDIF}

  {$IFNDEF GDIPLUSDRAWING}
  {$IFDEF CMNLIB}
  FCanvas.Refresh;
  {$ENDIF}
  {$ENDIF}

  AState.Free;
end;

function TAdvGraphics.SaveState(ACanvasOnly: Boolean = False): TAdvGraphicsSaveState;
begin
  Result := TAdvGraphicsSaveState.Create;

  if not ACanvasOnly then
  begin
    Result.Fill.Assign(FFill);
    Result.Stroke.Assign(FStroke);
    Result.Font.Assign(FFont);
  end;

  {$IFNDEF GDIPLUSDRAWING}
  {$IFDEF CMNLIB}
  FCanvas.Refresh;
  {$ENDIF}
  {$ENDIF}

  {$IFDEF NATIVEIOSDRAWING}
  CGContextSaveGState(FContext);
  {$ENDIF}
  {$IFDEF FMXLIB}
  Result.SaveDC := FCanvas.SaveState;
  {$ENDIF}
  {$IFDEF GDIPLUSDRAWING}
  Result.SaveDC := FGDIPCanvas.Save;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  {$IFDEF VCLLIB}
  Result.SaveDC := SaveDC(FCanvas.Handle);
  {$ENDIF}
  {$IFDEF LCLLIB}
  FCanvas.SaveHandleState;
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.StopSpecialPen;
begin
  {$IFDEF GDIPLUSDRAWING}
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  {$IFDEF CMNLIB}
  DeleteObject(SelectObject(FCanvas.Handle, FOldPenHandle));
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.StartSpecialPen;
{$IFDEF GDIPLUSDRAWING}
{$ENDIF}
{$IFNDEF GDIPLUSDRAWING}
{$IFDEF CMNLIB}
var
  hpen: THandle;
  lb: TLogBrush;
{$ENDIF}
{$ENDIF}
begin
  {$IFDEF GDIPLUSDRAWING}
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  {$IFDEF CMNLIB}
  lb.lbColor := ColorToRGB(FCanvas.Pen.Color);
  lb.lbStyle := BS_SOLID;

  hpen := ExtCreatePen(PS_COSMETIC or PS_ALTERNATE, 1, lb, 0, nil);
  FOldPenHandle := SelectObject(FCanvas.Handle, hpen);
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.SetFill(AFill: TAdvGraphicsFill);
{$IFDEF FMXLIB}
var
  pt: TGradientPoint;
  {$IFDEF NATIVEIOSDRAWING}
  colorSpace: CGColorSpaceRef;
  colorarr: array of CGColorRef;
  locationarr: array of CGFloat;
  colors: CFArrayRef;
  {$ENDIF}
{$ENDIF}
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  {$IFDEF FMXLIB}
  FCanvas.Fill.Color := AFill.Color;
  case AFill.Kind of
    gfkSolid:
    begin
      FCanvas.Fill.Kind := TBrushKind.Solid;
    end;
    gfkGradient:
    begin
      FCanvas.Fill.Kind := TBrushKind.Gradient;
      FCanvas.Fill.Gradient.Points.Clear;

      if (AFill.ColorMirror <> gcNull) and (AFill.ColorMirrorTo <> gcNull) then
      begin
        pt := TGradientPoint(FCanvas.Fill.Gradient.Points.Add);
        pt.Color := AFill.Color;
        pt.Offset := 0;

        pt := TGradientPoint(FCanvas.Fill.Gradient.Points.Add);
        pt.Color := AFill.ColorTo;
        pt.Offset := 0.5;

        pt := TGradientPoint(FCanvas.Fill.Gradient.Points.Add);
        pt.Color := AFill.ColorMirror;
        pt.Offset := 0.5;

        pt := TGradientPoint(FCanvas.Fill.Gradient.Points.Add);
        pt.Color := AFill.ColorMirrorTo;
        pt.Offset := 1;
      end
      else
      begin
        pt := TGradientPoint(FCanvas.Fill.Gradient.Points.Add);
        pt.Color := AFill.Color;
        pt.Offset := 0;

        pt := TGradientPoint(FCanvas.Fill.Gradient.Points.Add);
        pt.Color := AFill.ColorTo;
        pt.Offset := 1;
      end;

      case AFill.Orientation of
        gfoHorizontal:
        begin
          FCanvas.Fill.Gradient.StartPosition.Point := PointF(0, 0.5);
          FCanvas.Fill.Gradient.StopPosition.Point := PointF(1, 0.5);
        end;
        gfoVertical:
        begin
          FCanvas.Fill.Gradient.StartPosition.Point := PointF(0.5, 0);
          FCanvas.Fill.Gradient.StopPosition.Point := PointF(0.5, 1);
        end;
      end;
    end
    else
      FCanvas.Fill.Kind := TBrushKind.None;
  end;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FCanvas.Brush.Color := AFill.Color;
  case AFill.Kind of
    gfkSolid, gfkGradient: FCanvas.Brush.Style := bsSolid;
    gfkNone: FCanvas.Brush.Style := bsClear;
  end;
  {$ENDIF}

  {$IFDEF NATIVEIOSDRAWING}
  case AFill.Kind of
    gfkSolid: CGContextSetRGBFillColor(FContext, GetColorRed(AFill.Color) / 255, GetColorGreen(AFill.Color) / 255, GetColorBlue(AFill.Color) / 255, GetColorAlpha(AFill.Color) / 255);
    gfkGradient:
    begin
      if Assigned(FContextGradient) then
      begin
        CFRelease(FContextGradient);
        FContextGradient := nil;
      end;

      colorSpace := CGColorSpaceCreateDeviceRGB;

      if (AFill.ColorMirror <> gcNull) and (AFill.ColorMirrorTo <> gcNull) then
      begin
        SetLength(colorarr, 4);
        SetLength(locationarr, 4);
        colorarr[0] := AlphaColorToUIColor(AFill.Color).CGColor;
        locationarr[0] := 0;
        colorarr[1] := AlphaColorToUIColor(AFill.ColorTo).CGColor;
        locationarr[1] := 0.5;
        colorarr[2] := AlphaColorToUIColor(AFill.ColorMirror).CGColor;
        locationarr[2] := 0.5;
        colorarr[3] := AlphaColorToUIColor(AFill.ColorMirrorTo).CGColor;
        locationarr[3] := 1;
      end
      else
      begin
        SetLength(colorarr, 2);
        SetLength(locationarr, 2);
        colorarr[0] := AlphaColorToUIColor(AFill.Color).CGColor;
        locationarr[0] := 0;
        colorarr[1] := AlphaColorToUIColor(AFill.ColorTo).CGColor;
        locationarr[0] := 1;
      end;

      colors := TNSArray.OCClass.arrayWithObjects(@colorarr[0], Length(colorarr));
      FContextGradient := CGGradientCreateWithColors(colorSpace, colors, @locationarr[0]);
      CFRelease(colorSpace);
    end;
  end;
  {$ENDIF}

  FFill.Assign(AFill);
  FBlockUpdate := False;
end;

procedure TAdvGraphics.SetFillKind(AKind: TAdvGraphicsFillKind);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  {$IFDEF FMXLIB}
  FCanvas.Fill.Kind := TBrushKind(Integer(AKind));
  {$ENDIF}
  {$IFDEF CMNLIB}
  case AKind of
    gfkNone: FCanvas.Brush.Style := bsClear;
    gfkSolid, gfkGradient: FCanvas.Brush.Style := bsSolid;
  end;
  {$ENDIF}
  {$IFDEF NATIVEIOSDRAWING}
  {$ENDIF}

  FFill.Kind := AKind;
  FBlockUpdate := False;
end;

procedure TAdvGraphics.SetFillColor(AColor: TAdvGraphicsColor);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  {$IFDEF FMXLIB}
  FCanvas.Fill.Color := AColor;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FCanvas.Brush.Color := AColor;
  {$ENDIF}
  {$IFDEF NATIVEIOSDRAWING}
  CGContextSetRGBFillColor(FContext, GetColorRed(AColor) / 255, GetColorGreen(AColor) / 255, GetColorBlue(AColor) / 255, GetColorAlpha(AColor) / 255);
  {$ENDIF}

  FFill.Color := AColor;
  FBlockUpdate := False;
end;

procedure TAdvGraphics.SetStrokeKind(AKind: TAdvGraphicsStrokeKind);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  {$IFDEF FMXLIB}
  case AKind of
    gskNone: FCanvas.Stroke.Kind := TBrushKind.None;
    gskSolid:
    begin
      FCanvas.StrokeDash := TStrokeDash.Solid;
      FCanvas.Stroke.Kind := TBrushKind.Solid;
    end;
    gskDash:
    begin
      FCanvas.StrokeDash := TStrokeDash.Dash;
      FCanvas.Stroke.Kind := TBrushKind.Solid;
    end;
    gskDot:
    begin
      FCanvas.StrokeDash := TStrokeDash.Dot;
      FCanvas.Stroke.Kind := TBrushKind.Solid;
    end;
    gskDashDot:
    begin
      FCanvas.StrokeDash := TStrokeDash.DashDot;
      FCanvas.Stroke.Kind := TBrushKind.Solid;
    end;
    gskDashDotDot:
    begin
      FCanvas.StrokeDash := TStrokeDash.DashDotDot;
      FCanvas.Stroke.Kind := TBrushKind.Solid;
    end;
  end;
  {$ENDIF}
  {$IFDEF CMNLIB}
  case AKind of
    gskNone: FCanvas.Pen.Style := psClear;
    gskSolid: FCanvas.Pen.Style := psSolid;
    gskDash: FCanvas.Pen.Style := psDash;
    gskDot: FCanvas.Pen.Style := psDot;
    gskDashDot: FCanvas.Pen.Style := psDashDot;
    gskDashDotDot: FCanvas.Pen.Style := psDashDotDot;
  end;
  {$ENDIF}
  {$IFDEF NATIVEIOSDRAWING}
  {$ENDIF}

  FStroke.Kind := AKind;
  FBlockUpdate := False;
end;

procedure TAdvGraphics.SetStroke(AStroke: TAdvGraphicsStroke);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  {$IFDEF FMXLIB}
  FCanvas.Stroke.Color := AStroke.Color;
  FCanvas.Stroke.Thickness := AStroke.Width;
  case AStroke.Kind of
    gskSolid:
    begin
      FCanvas.Stroke.Kind := TBrushKind.Solid;
      FCanvas.Stroke.Dash := TStrokeDash.Solid;
    end;
    gskNone: FCanvas.Stroke.Kind := TBrushKind.None;
    else
      FCanvas.Stroke.Kind := TBrushKind.Solid;
  end;

  case AStroke.Kind of
    gskDash: FCanvas.Stroke.Dash := TStrokeDash.Dash;
    gskDot: FCanvas.Stroke.Dash := TStrokeDash.Dot;
    gskDashDot: FCanvas.Stroke.Dash := TStrokeDash.DashDot;
    gskDashDotDot: FCanvas.Stroke.Dash := TStrokeDash.DashDotDot;
  end;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FCanvas.Pen.Color := AStroke.Color;
  FCanvas.Pen.Width := Round(AStroke.Width);
  case AStroke.Kind of
    gskSolid: FCanvas.Pen.Style := psSolid;
    gskNone: FCanvas.Pen.Style := psClear;
    gskDash: FCanvas.Pen.Style := psDash;
    gskDot: FCanvas.Pen.Style := psDot;
    gskDashDot: FCanvas.Pen.Style := psDash;
    gskDashDotDot: FCanvas.Pen.Style := psDashDotDot;
  end;
  {$ENDIF}
  {$IFDEF NATIVEIOSDRAWING}
  CGContextSetRGBStrokeColor(FContext, GetColorRed(AStroke.Color) / 255, GetColorGreen(AStroke.Color) / 255, GetColorBlue(AStroke.Color) / 255, GetColorAlpha(AStroke.Color) / 255);
  CGContextSetLineWidth(FContext, AStroke.Width);
  case AStroke.Kind of
    gskSolid: ;
    gskNone: ;
    gskDash: ;
    gskDot: ;
    gskDashDot: ;
    gskDashDotDot: ;
  end;
  {$ENDIF}

  FStroke.Assign(AStroke);
  FBlockUpdate := False;
end;

procedure TAdvGraphics.SetStrokeWidth(AWidth: Single);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  {$IFDEF FMXLIB}
  FCanvas.Stroke.Thickness := AWidth;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FCanvas.Pen.Width := Round(AWidth);
  {$ENDIF}
  {$IFDEF NATIVEIOSDRAWING}
  CGContextSetLineWidth(FContext, AWidth);
  {$ENDIF}

  FStroke.Width := AWidth;
  FBlockUpdate := False;
end;

procedure TAdvGraphics.SetStrokeColor(AColor: TAdvGraphicsColor);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  {$IFDEF FMXLIB}
  FCanvas.Stroke.Color := AColor;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FCanvas.Pen.Color := AColor;
  {$ENDIF}
  {$IFDEF NATIVEIOSDRAWING}
  CGContextSetRGBStrokeColor(FContext, GetColorRed(AColor) / 255, GetColorGreen(AColor) / 255, GetColorBlue(AColor) / 255, GetColorAlpha(AColor) / 255);
  {$ENDIF}

  FStroke.Color := AColor;
  FBlockUpdate := False;
end;

procedure TAdvGraphics.DrawLine(AFromPoint: TPoint; AToPoint: TPoint; AModifyPointModeFrom: TAdvGraphicsModifyPointMode = gcpmRightDown;
  AModifyPointModeTo: TAdvGraphicsModifyPointMode = gcpmRightDown);
begin
  DrawLine(ConvertToPointF(AFromPoint), ConvertToPointF(AToPoint), AModifyPointModeFrom, AModifyPointModeTo);
end;

procedure TAdvGraphics.DrawLine(AFromPoint: TPointF; AToPoint: TPointF; AModifyPointModeFrom: TAdvGraphicsModifyPointMode = gcpmRightDown;
  AModifyPointModeTo: TAdvGraphicsModifyPointMode = gcpmRightDown);
{$IFDEF GDIPLUSDRAWING}
var
  p: TGPPen;
{$ENDIF}
begin
  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    {$IFDEF FMXLIB}
    AFromPoint := ModifyPoint(AFromPoint, AModifyPointModeFrom);
    AToPoint := ModifyPoint(AToPoint, AModifyPointModeTo);
    {$IFDEF NATIVEIOSDRAWING}
    CGContextMoveToPoint(FContext, AFromPoint.X, AFromPoint.Y);
    CGContextAddLineToPoint(FContext, AToPoint.X, AToPoint.Y);
    CGContextStrokePath(FContext);
    {$ELSE}
    FCanvas.DrawLine(AFromPoint, AToPoint, FStroke.Opacity);
    {$ENDIF}
    {$ENDIF}
    {$IFDEF CMNLIB}
    {$IFDEF GDIPLUSDRAWING}
    p := CreateGDIPStroke(Stroke);
    try
      FGDIPCanvas.DrawLine(p, AFromPoint.X, AFromPoint.Y, AToPoint.X, AToPoint.Y);
    finally
      p.Free;
    end;
    {$ENDIF}
    {$IFNDEF GDIPLUSDRAWING}
    FCanvas.MoveTo(Round(AFromPoint.X), Round(AFromPoint.Y));
    FCanvas.LineTo(Round(AToPoint.X), Round(AToPoint.Y));
    {$ENDIF}
    {$ENDIF}
  end;
end;

procedure TAdvGraphics.DrawPolyline(APolyline: TAdvGraphicsPathPolygon);
{$IFDEF CMNLIB}
{$IFDEF GDIPLUSDRAWING}
var
  p: TGPPen;
  b: TGPBrush;
  pts: TPointFDynArray;
{$ENDIF}
{$IFNDEF GDIPLUSDRAWING}
var
  pts: array of TPoint;
  I: Integer;
  ps: TPenStyle;
  bs: TBrushStyle;
  c: TAdvGraphicsColor;
{$ENDIF}
{$ENDIF}
{$IFDEF NATIVEIOSDRAWING}
var
  I: Integer;
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  {$IFDEF NATIVEIOSDRAWING}
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
  begin
    if Length(APolyLine) > 0 then
    begin
      CGContextMoveToPoint(FContext, APolyLine[0].X, APolyLine[0].Y);
      for I := 1 to Length(APolyline) - 1 do
        CGContextAddLineToPoint(FContext, APolyLine[I].X, APolyLine[I].Y);
    end;

    CGContextFillPath(FContext);
  end;

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    if Length(APolyLine) > 0 then
    begin
      CGContextMoveToPoint(FContext, APolyLine[0].X, APolyLine[0].Y);
      for I := 1 to Length(APolyline) - 1 do
        CGContextAddLineToPoint(FContext, APolyLine[I].X, APolyLine[I].Y);
    end;

    CGContextStrokePath(FContext);
  end;
  {$ELSE}
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    FCanvas.FillPolygon(TPolygon(APolyline), FFill.Opacity);

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
    FCanvas.DrawPolygon(TPolygon(APolyline), FStroke.Opacity);
  {$ENDIF}
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
  begin
    b := CreateGDIPFill(Fill, PolyToGDIPRect(APolyLine));
    try
      pts := PolyToGDIPPoints(APolyLine);
      FGDIPCanvas.FillPolygon(b, PGPpointF(pts), Length(pts));
    finally
      b.Free;
    end;
  end;

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    p := CreateGDIPStroke(Stroke);
    try
      pts := PolyToGDIPPoints(APolyLine);
      FGDIPCanvas.DrawLines(p, PGPpointF(pts), Length(pts));
    finally
      p.Free;
    end;
  end;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  SetLength(pts, Length(APolyline) - 1);
  for I := 0 to Length(APolyline) - 2 do
    pts[I] := Point(Round(APolyline[I].X), Round(APolyline[I].Y));

  ps := FCanvas.Pen.Style;
  FCanvas.Pen.Style := psClear;
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    FCanvas.Polyline(pts);
  FCanvas.Pen.Style := ps;

  c := FCanvas.Brush.Color;
  bs := FCanvas.Brush.Style;
  FCanvas.Brush.Style := bsClear;
  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
    FCanvas.Polyline(pts);
  FCanvas.Brush.Style := bs;
  FCanvas.Brush.Color := c;
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.DrawPolygon(APolygon: TAdvGraphicsPathPolygon);
{$IFDEF CMNLIB}
{$IFDEF GDIPLUSDRAWING}
var
  p: TGPPen;
  b: TGPBrush;
  pts: TPointFDynArray;
{$ENDIF}
{$IFNDEF GDIPLUSDRAWING}
var
  pts: array of TPoint;
  I: Integer;
  ps: TPenStyle;
  bs: TBrushStyle;
  c: TAdvGraphicsColor;
{$ENDIF}
{$ENDIF}
{$IFDEF NATIVEIOSDRAWING}
var
  I: Integer;
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  {$IFDEF NATIVEIOSDRAWING}
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
  begin
    if Length(APolygon) > 0 then
    begin
      CGContextMoveToPoint(FContext, APolygon[0].X, APolygon[0].Y);
      for I := 1 to Length(APolygon) - 1 do
        CGContextAddLineToPoint(FContext, APolygon[I].X, APolygon[I].Y);
    end;

    CGContextFillPath(FContext);
  end;

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    if Length(APolygon) > 0 then
    begin
      CGContextMoveToPoint(FContext, APolygon[0].X, APolygon[0].Y);
      for I := 1 to Length(APolygon) - 1 do
        CGContextAddLineToPoint(FContext, APolygon[I].X, APolygon[I].Y);
    end;

    CGContextStrokePath(FContext);
  end;
  {$ELSE}
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    FCanvas.FillPolygon(TPolygon(APolygon), FFill.Opacity);

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
    FCanvas.DrawPolygon(TPolygon(APolygon), FStroke.Opacity);
  {$ENDIF}
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
  begin
    b := CreateGDIPFill(Fill, PolyToGDIPRect(APolygon));
    try
      pts := PolyToGDIPPoints(APolygon);
      FGDIPCanvas.FillPolygon(b, PGPpointF(pts), Length(pts));
    finally
      b.Free;
    end;
  end;

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    p := CreateGDIPStroke(Stroke);
    try
      pts := PolyToGDIPPoints(APolygon);
      FGDIPCanvas.DrawPolygon(p, PGPpointF(pts), Length(pts));
    finally
      p.Free;
    end;
  end;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  SetLength(pts, Length(APolygon) - 1);
  for I := 0 to Length(APolygon) - 2 do
    pts[I] := Point(Round(APolygon[I].X), Round(APolygon[I].Y));

  ps := FCanvas.Pen.Style;
  FCanvas.Pen.Style := psClear;
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    FCanvas.Polygon(pts);
  FCanvas.Pen.Style := ps;

  c := FCanvas.Brush.Color;
  bs := FCanvas.Brush.Style;
  FCanvas.Brush.Style := bsClear;
  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
    FCanvas.Polygon(pts);
  FCanvas.Brush.Style := bs;
  FCanvas.Brush.Color := c;
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.DrawPath(APath: TAdvGraphicsPath; APathMode: TAdvGraphicsPathDrawMode = pdmPolygon);
var
  p: TAdvGraphicsPathPolygon;
begin
  if Assigned(APath) then
  begin
    SetLength(p, 0);
    APath.FlattenToPolygon(p);
    case APathMode of
      pdmPolygon: DrawPolygon(p);
      pdmPolyline: DrawPolyline(p);
    end;
  end;
end;

procedure TAdvGraphics.DrawArc(const Center: TPoint; const Radius: TPoint; StartAngle: Integer; SweepAngle: Integer);
begin
  DrawArc(ConvertToPointF(Center), ConvertToPointF(Radius), StartAngle, SweepAngle);
end;

procedure TAdvGraphics.DrawArc(const Center: TPointF; const Radius: TPointF; StartAngle: Single; SweepAngle: Single);
{$IFDEF CMNLIB}
{$IFDEF GDIPLUSDRAWING}
var
  p: TGPPen;
{$ENDIF}
{$IFNDEF GDIPLUSDRAWING}
var
  x, y, xs, ys, sx, sy, sxs, sys: Integer;
  ps: TPenStyle;
  bs: TBrushStyle;
  c: TAdvGraphicsColor;
{$ENDIF}
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  {$IFDEF NATIVEIOSDRAWING}
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
  begin
    CGContextAddArc(FContext, Center.X, Center.Y, Radius.X, StartAngle, StartAngle + SweepAngle, Integer(StartAngle + SweepAngle > 0));
    CGContextFillPath(FContext);
  end;

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    CGContextAddArc(FContext, Center.X, Center.Y, Radius.X, StartAngle, StartAngle + SweepAngle, Integer(StartAngle + SweepAngle > 0));
    CGContextStrokePath(FContext);
  end;
  {$ELSE}
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    FCanvas.FillArc(Center, Radius, StartAngle, SweepAngle, FFill.Opacity);

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
    FCanvas.DrawArc(Center, Radius, StartAngle, SweepAngle, FFill.Opacity);
  {$ENDIF}
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  p := CreateGDIPStroke(Stroke);
  try
    FGDIPCanvas.DrawArc(p, Center.X - Radius.X, Center.Y - Radius.Y, Radius.X * 2, Radius.Y * 2, StartAngle, SweepAngle);
  finally
    p.Free;
  end;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  sx := Floor(Center.X - Radius.X);
  sy := Floor(Center.Y - Radius.Y);
  sxs := Floor(Center.X + Radius.X);
  sys := Floor(Center.Y + Radius.Y);

  x := Floor(Center.X + (Radius.X * COS(DegToRad(-StartAngle - SweepAngle))));
  y := Floor(Center.Y - (Radius.Y * SIN(DegToRad(-StartAngle - SweepAngle))));
  xs := Floor(Center.X + (Radius.X * COS(DegToRad(-StartAngle))));
  ys := Floor(Center.Y - (Radius.Y * SIN(DegToRad(- StartAngle))));

  ps := FCanvas.Pen.Style;
  FCanvas.Pen.Style := psClear;
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    FCanvas.Arc(sx, sy, sxs, sys, x, y, xs, ys);
  FCanvas.Pen.Style := ps;

  c := FCanvas.Brush.Color;
  bs := FCanvas.Brush.Style;
  FCanvas.Brush.Style := bsClear;
  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
    FCanvas.Arc(sx, sy, sxs, sys, x, y, xs, ys);
  FCanvas.Brush.Style := bs;
  FCanvas.Brush.Color := c;
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.DrawRoundRectangle(ARect: TRect; ARounding: Integer = 10; ACorners: TAdvGraphicsCorners = [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight]; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawRoundRectangle(ConvertToRectF(ARect), ARounding, ACorners);
end;

procedure TAdvGraphics.DrawRoundRectangle(ARect: TRectF; ARounding: Single = 10; ACorners: TAdvGraphicsCorners = [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight]; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawRoundRectangle(ARect.Left, ARect.Top, ARect.Right, ARect.Bottom, ARounding, ACorners, AModifyRectMode);
end;

procedure TAdvGraphics.DrawRectangle(ALeft: Integer; ATop: Integer; ARight: Integer; ABottom: Integer; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawRectangle(RectF(ALeft, ATop, ARight, ABottom), AModifyRectMode);
end;

procedure TAdvGraphics.DrawRectangle(ALeft: Double; ATop: Double; ARight: Double; ABottom: Double; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawRectangle(ALeft, ATop, ARight, ABottom, AllSides, AModifyRectMode);
end;

procedure TAdvGraphics.DrawRectangle(ALeft: Integer; ATop: Integer; ARight: Integer; ABottom: Integer; ASides: TAdvGraphicsSides; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawRectangle(RectF(ALeft, ATop, ARight, ABottom), ASides, AModifyRectMode);
end;

procedure TAdvGraphics.DrawRectangle(ALeft: Double; ATop: Double; ARight: Double; ABottom: Double; ASides: TAdvGraphicsSides; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
var
{$IFDEF FMXLIB}
  r: TRectF;
{$ENDIF}
{$IFDEF CMNLIB}
{$IFDEF GDIPLUSDRAWING}
  r: TGPRectF;
  b: TGPBrush;
{$ENDIF}
{$IFNDEF GDIPLUSDRAWING}
  r: TRect;
  ps: TPenStyle;
  c: TAdvGraphicsColor;
  bs: TBrushStyle;
{$ENDIF}
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  r := RectF(ALeft, ATop, ARight, ABottom);
  r := ModifyRect(r, AModifyRectMode);
  {$IFDEF NATIVEIOSDRAWING}
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
  begin
    case FFill.Kind of
      gfkSolid: CGContextFillRect(FContext, CGRectMake(r.Left, r.Top, r.Width, r.Height));
      gfkGradient:
      begin
        case FFill.Orientation of
          gfoHorizontal: CGContextDrawLinearGradient(FContext, FContextGradient, CGPointMake(r.Left, r.Top + r.Height / 2), CGPointMake(r.Right, r.Top + r.Height / 2), 0);
          gfoVertical: CGContextDrawLinearGradient(FContext, FContextGradient, CGPointMake(r.Left + r.Width / 2, r.Top), CGPointMake(r.Left + R.Width / 2, r.Bottom), 0);
        end;
      end;
    end;
  end;
  {$ELSE}
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    FCanvas.FillRect(r, 0, 0, AllCorners, FFill.Opacity);
  {$ENDIF}

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    if gsTop in ASides then
      DrawLine(PointF(r.Left, r.Top), PointF(r.Right, r.Top));
    if gsLeft in ASides then
      DrawLine(PointF(r.Left, r.Top), PointF(r.Left, r.Bottom));
    if gsBottom in ASides then
      DrawLine(PointF(r.Left, r.Bottom), PointF(r.Right, r.Bottom));
    if gsRight in ASides then
      DrawLine(PointF(r.Right, r.Top), PointF(r.Right, r.Bottom));
  end;
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  r := MakeRect(ALeft, ATop, ARight - ALeft, ABottom - ATop);
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
  begin
    b := CreateGDIPFill(Fill, r);
    try
      FGDIPCanvas.FillRectangle(b, r);
    finally
      b.Free;
    end;
  end;

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    if gsTop in ASides then
      DrawLine(PointF(r.X, r.Y), PointF(r.X + r.Width - 1, r.Y));
    if gsLeft in ASides then
      DrawLine(PointF(r.X, r.Y), PointF(r.X, r.Y + r.Height - 1));
    if gsBottom in ASides then
      DrawLine(PointF(r.X, r.Y + r.Height - 1), PointF(r.X + r.Width - 1, r.Y + r.Height - 1));
    if gsRight in ASides then
      DrawLine(PointF(r.X + r.Width - 1, r.Y), PointF(r.X + r.Width - 1, r.Y + r.Height - 1));
  end;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  r := Rect(Round(ALeft), Round(ATop), Round(ARight), Round(ABottom));

  c := gcNull;
  bs := bsClear;
  if (FFill.Kind = gfkGradient) then
  begin
    if (FFill.Color <> gcNull) and (FFill.ColorTo <> gcNull) then
    begin
      if (FFill.ColorMirror <> gcNull) and (FFill.ColorMirrorTo <> gcNull) then
      begin
        case FFill.Orientation of
          gfoHorizontal:
          begin
            DrawGradient(FCanvas, FFill.Color, FFill.ColorTo, Rect(r.Left, r.Top, r.Left + (r.Right - r.Left) div 2, r.Bottom), 0, [], True);
            DrawGradient(FCanvas, FFill.ColorMirror, FFill.ColorMirrorTo, Rect(r.Left + (r.Right - r.Left) div 2, r.Top, r.Right, r.Bottom), 0, [], True);
          end;
          gfoVertical:
          begin
            DrawGradient(FCanvas, FFill.Color, FFill.ColorTo, Rect(r.Left, r.Top, r.Right, r.Top + (r.Bottom - r.Top) div 2), 0, [], False);
            DrawGradient(FCanvas, FFill.ColorMirror, FFill.ColorMirrorTo, Rect(r.Left, r.Top + (r.Bottom - r.Top) div 2, r.Right, r.Bottom), 0, [], False);
          end;
        end;
      end
      else
        DrawGradient(FCanvas, FFill.Color, FFill.ColorTo, r, 0, [], FFill.Orientation = gfoHorizontal);
    end;

    c := FCanvas.Brush.Color;
    bs := FCanvas.Brush.Style;
    FCanvas.Brush.Style := bsClear;
  end;

  ps := FCanvas.Pen.Style;
  FCanvas.Pen.Style := psClear;
  if (FFill.Color <> gcNull) and (FFill.Kind = gfkSolid) then
    FCanvas.Rectangle(r);
  FCanvas.Pen.Style := ps;

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    if gsTop in ASides then
      DrawLine(PointF(r.Left, r.Top), PointF(r.Right - 1, r.Top));
    if gsLeft in ASides then
      DrawLine(PointF(r.Left, r.Top), PointF(r.Left, r.Bottom - 1));
    if gsBottom in ASides then
      DrawLine(PointF(r.Left, r.Bottom - 1), PointF(r.Right - 1, r.Bottom - 1));
    if gsRight in ASides then
      DrawLine(PointF(r.Right - 1, r.Top), PointF(r.Right - 1, r.Bottom));
  end;

  if FFill.Kind = gfkGradient then
  begin
    FCanvas.Brush.Color := c;
    FCanvas.Brush.Style := bs;
  end;
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.DrawRoundRectangle(ALeft: Integer; ATop: Integer; ARight: Integer; ABottom: Integer; ARounding: Integer = 10; ACorners: TAdvGraphicsCorners = [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight]; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawRoundRectangle(RectF(ALeft, ATop, ARight, ABottom), ARounding, ACorners);
end;

procedure TAdvGraphics.DrawRoundRectangle(ALeft: Double; ATop: Double; ARight: Double; ABottom: Double; ARounding: Single = 10; ACorners: TAdvGraphicsCorners = [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight]; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
var
{$IFDEF NATIVEIOSDRAWING}
  co: Cardinal;
{$ENDIF}
{$IFDEF FMXLIB}
  r: TRectF;
  {$IFNDEF NATIVEIOSDRAWING}
  c: TCorners;
  {$ENDIF}
{$ENDIF}
{$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  r: TRectF;
  rg: TGPRectF;
  rc: Single;
  pth: TAdvGraphicsPath;
  b: TGPBrush;
  p: TGPPen;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  r, rg: TRect;
  c: TAdvGraphicsCorners;
  rc: Integer;
  cl: TAdvGraphicsColor;
  bs: TBrushStyle;

  procedure CanvasArc(Center, Radius: TPoint; StartAngle, SweepAngle: Integer);
  var
    sx, sy, sxs, sys, x, y, xs, ys: Integer;
  begin
    sx := Center.X - Radius.X;
    sy := Center.Y - Radius.Y;
    sxs := Center.X + Radius.X;
    sys := Center.Y + Radius.Y;

    x := Center.X + Round(Radius.X * COS(DegToRad(-StartAngle - SweepAngle)));
    y := Center.Y - Round(Radius.Y * SIN(DegToRad(-StartAngle - SweepAngle)));
    xs := Center.X + Round(Radius.X * COS(DegToRad(-StartAngle)));
    ys := Center.Y - Round(Radius.Y * SIN(DegToRad(- StartAngle)));

    Canvas.Arc(sx, sy, sxs, sys, x, y, xs, ys);
  end;
  {$ENDIF}
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  r := RectF(ALeft, ATop, ARight, ABottom);
  r := ModifyRect(r, AModifyRectMode);
  {$IFDEF NATIVEIOSDRAWING}
  co := 0;
  if gcTopLeft in ACorners then
    co := co or UIRectCornerTopLeft;

  if gcTopRight in ACorners then
    co := co or UIRectCornerTopRight;

  if gcBottomLeft in ACorners then
    co := co or UIRectCornerBottomLeft;

  if gcBottomRight in ACorners then
    co := co or UIRectCornerBottomRight;

  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
  begin
    case FFill.Kind of
      gfkSolid:
      begin
        CGContextAddPath(FContext, TUIBezierPath.Wrap(TUIBezierPath.OCClass.bezierPathWithRoundedRect(CGRectMake(r.Left, r.Top, r.Width, r.Height), co, CGSizeMake(ARounding, ARounding))).CGPath);
        CGContextFillPath(FContext);
      end;
      gfkGradient:
      begin
        CGContextSaveGState(FContext);
        CGContextAddPath(FContext, TUIBezierPath.Wrap(TUIBezierPath.OCClass.bezierPathWithRoundedRect(CGRectMake(r.Left, r.Top, r.Width, r.Height), co, CGSizeMake(ARounding, ARounding))).CGPath);
        CGContextClip(FContext);
        case FFill.Orientation of
          gfoHorizontal: CGContextDrawLinearGradient(FContext, FContextGradient, CGPointMake(r.Left, r.Top + r.Height / 2), CGPointMake(r.Right, r.Top + r.Height / 2), 0);
          gfoVertical: CGContextDrawLinearGradient(FContext, FContextGradient, CGPointMake(r.Left + r.Width / 2, r.Top), CGPointMake(r.Left + R.Width / 2, r.Bottom), 0);
        end;
        CGContextRestoreGState(FContext);
      end;
    end;
  end;

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    CGContextAddPath(FContext, TUIBezierPath.Wrap(TUIBezierPath.OCClass.bezierPathWithRoundedRect(CGRectMake(r.Left, r.Top, r.Width, r.Height), co, CGSizeMake(ARounding, ARounding))).CGPath);
    CGContextStrokePath(FContext);
  end;
  {$ELSE}
  c := [];
  if gcTopLeft in ACorners then
    c := c + [TCorner.TopLeft];

  if gcTopRight in ACorners then
    c := c + [TCorner.TopRight];

  if gcBottomLeft in ACorners then
    c := c + [TCorner.BottomLeft];

  if gcBottomRight in ACorners then
    c := c + [TCorner.BottomRight];

  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    FCanvas.FillRect(r, ARounding, ARounding, c, FFill.Opacity);

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
    FCanvas.DrawRect(r, ARounding, ARounding, c, FStroke.Opacity);
  {$ENDIF}
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  r := RectF(ALeft, ATop, ARight, ABottom);
  r.Width := r.Width - 1;
  r.Height := r.Height - 1;
  rg := MakeRect(r.Left, r.Top, r.Width, r.Height);
  rc := ARounding;

  if ACorners = [] then
  begin
    if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    begin
      b := CreateGDIPFill(Fill, rg);
      try
        FGDIPCanvas.FillRectangle(b, rg)
      finally
        b.Free;
      end;
    end;

    if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
    begin
      p := CreateGDIPStroke(Stroke);
      try
        FGDIPCanvas.DrawRectangle(p, rg);
      finally
        p.Free;
      end;
    end;
  end
  else
  begin
    pth := TAdvGraphicsPath.Create;
    try
      if gcBottomLeft in ACorners then
      begin
        pth.MoveTo(PointF(r.Left + rc, r.Bottom));
        pth.AddArc(PointF(r.Left + rc, r.Bottom - rc), PointF(rc, rc), -270, 90);
        pth.LineTo(PointF(r.Left, r.Bottom - rc));
      end
      else
      begin
        pth.MoveTo(PointF(r.Left, r.Bottom));
      end;

      if gcTopLeft in ACorners then
      begin
        pth.LineTo(PointF(r.Left, r.Top + rc));
        pth.AddArc(PointF(r.Left + rc, r.Top + rc), PointF(rc, rc), -180, 90);
        pth.LineTo(PointF(r.Left + rc, r.Top));
      end
      else
        pth.LineTo(PointF(r.Left, r.Top));

      if gcTopRight in ACorners then
      begin
        pth.LineTo(PointF(r.Right - rc, r.Top));
        pth.AddArc(PointF(r.Right - rc, r.Top + rc), PointF(rc, rc), -90, 90);
        pth.LineTo(PointF(r.Right, r.Top + rc));
      end
      else
        pth.LineTo(PointF(r.Right, r.Top));

      if gcBottomRight in ACorners then
      begin
        pth.LineTo(PointF(r.Right, r.Bottom - rc));
        pth.AddArc(PointF(r.Right - rc, r.Bottom - rc), PointF(rc, rc), 0, 90);
        pth.LineTo(PointF(r.Right - rc, r.Bottom));
      end
      else
        pth.LineTo(PointF(r.Right, r.Bottom));

      if gcBottomLeft in ACorners then
        pth.LineTo(PointF(r.Left + rc, r.Bottom))
      else
        pth.LineTo(PointF(r.Left, r.Bottom));

      pth.ClosePath;

      DrawPath(pth, pdmPolygon);
    finally
      pth.Free;
    end;
  end;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  r := Rect(Round(ALeft), Round(ATop), Round(ARight), Round(ABottom));

  rg := r;
  rg.Bottom := rg.Bottom - 1;
  rg.Right := rg.Right - 1;

  if (FFill.Kind = gfkGradient) then
  begin
    if (FFill.Color <> gcNull) and (FFill.ColorTo <> gcNull) then
    begin
      if (FFill.ColorMirror <> gcNull) and (FFill.ColorMirrorTo <> gcNull) then
      begin
        case FFill.Orientation of
          gfoHorizontal:
          begin
            c := [];
            if gcTopLeft in ACorners then
              c := c + [gcTopLeft];
            if gcBottomLeft in ACorners then
              c := c + [gcBottomLeft];

            DrawGradient(FCanvas, FFill.Color, FFill.ColorTo, Rect(rg.Left, rg.Top, rg.Left + (rg.Right - rg.Left) div 2, r.Bottom), ARounding, c, True);

            c := [];
            if gcTopRight in ACorners then
              c := c + [gcTopRight];
            if gcBottomRight in ACorners then
              c := c + [gcBottomRight];

            DrawGradient(FCanvas, FFill.ColorMirror, FFill.ColorMirrorTo, Rect(rg.Left + (rg.Right - r.Left) div 2, rg.Top, rg.Right, rg.Bottom), ARounding, c, True);
          end;
          gfoVertical:
          begin
            c := [];
            if gcTopLeft in ACorners then
              c := c + [gcTopLeft];
            if gcTopRight in ACorners then
              c := c + [gcTopRight];

            DrawGradient(FCanvas, FFill.Color, FFill.ColorTo, Rect(rg.Left, rg.Top, rg.Right, rg.Top + (rg.Bottom - rg.Top) div 2), ARounding, c, False);

            c := [];
            if gcBottomLeft in ACorners then
              c := c + [gcBottomLeft];
            if gcBottomRight in ACorners then
              c := c + [gcBottomRight];

            DrawGradient(FCanvas, FFill.ColorMirror, FFill.ColorMirrorTo, Rect(rg.Left, rg.Top + (rg.Bottom - rg.Top) div 2, rg.Right, rg.Bottom), ARounding, c, False);
          end;
        end;
      end
      else
        DrawGradient(FCanvas, FFill.Color, FFill.ColorTo, rg, ARounding, ACorners, FFill.Orientation = gfoHorizontal);
    end;
  end
  else if (FFill.Color <> gcNull) and (FFill.Kind = gfkSolid) then
    DrawGradient(FCanvas, FFill.Color, FFill.Color, r, ARounding, ACorners, FFill.Orientation = gfoHorizontal);

  cl := FCanvas.Brush.Color;
  bs := FCanvas.Brush.Style;
  FCanvas.Brush.Style := bsClear;

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    rc := Round(ARounding);
    if ACorners = [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight] then
      FCanvas.RoundRect(r, rc * 2, rc * 2)
    else if ACorners = [] then
      FCanvas.Rectangle(r)
    else
    begin
      r.Right := r.Right - 1;
      r.Bottom := r.Bottom - 1;
      rc := rc - 1;
      if gcBottomLeft in ACorners then
      begin
        FCanvas.MoveTo(r.Left + rc, r.Bottom);
        CanvasArc(Point(r.Left + rc, r.Bottom - rc), Point(rc, rc), -270, 90);
        FCanvas.MoveTo(r.Left, r.Bottom - rc);
      end
      else
      begin
        FCanvas.MoveTo(r.Left, r.Bottom);
      end;

      if gcTopLeft in ACorners then
      begin
        FCanvas.LineTo(r.Left, r.Top + rc - 2);
        CanvasArc(Point(r.Left + rc, r.Top + rc), Point(rc, rc), -180, 90);
        FCanvas.MoveTo(r.Left + rc, r.Top);
      end
      else
        FCanvas.LineTo(r.Left, r.Top);

      if gcTopRight in ACorners then
      begin
        FCanvas.LineTo(r.Right - rc, r.Top);
        CanvasArc(Point(r.Right - rc, r.Top + rc), Point(rc, rc), -90, 90);
        FCanvas.MoveTo(r.Right, r.Top + rc);
      end
      else
        FCanvas.LineTo(r.Right, r.Top);

      if gcBottomRight in ACorners then
      begin
        FCanvas.LineTo(r.Right, r.Bottom - rc + 1);
        CanvasArc(Point(r.Right - rc, r.Bottom - rc + 1), Point(rc, rc), 0, 90);
        FCanvas.MoveTo(r.Right - rc, r.Bottom);
      end
      else
      begin
        FCanvas.LineTo(r.Right, r.Bottom);
      end;

      if gcBottomLeft in ACorners then
        FCanvas.LineTo(r.Left + rc - 2, r.Bottom)
      else
        FCanvas.LineTo(r.Left, r.Bottom);
    end;
  end;

  FCanvas.Brush.Color := cl;
  FCanvas.Brush.Style := bs;
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.DrawRectangle(ARect: TRect; ASides: TAdvGraphicsSides; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawRectangle(ConvertToRectF(ARect), ASides, AModifyRectMode);
end;

procedure TAdvGraphics.DrawRectangle(ARect: TRectF; ASides: TAdvGraphicsSides; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawRectangle(ARect.Left, ARect.Top, ARect.Right, ARect.Bottom, ASides, AModifyRectMode);
end;

procedure TAdvGraphics.DrawRectangle(ARect: TRect; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawRectangle(ConvertToRectF(ARect), AModifyRectMode);
end;

procedure TAdvGraphics.DrawRectangle(ARect: TRectF; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawRectangle(ARect.Left, ARect.Top, ARect.Right, ARect.Bottom, AModifyRectMode);
end;

procedure TAdvGraphics.SetFontSize(ASize: Integer);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  FCanvas.Font.Size := ASize;
  FFont.Size := ASize;
  FBlockUpdate := False;
end;

procedure TAdvGraphics.SetFontColor(AColor: TAdvGraphicsColor);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  {$IFDEF FMXLIB}
  FCanvas.Fill.Color := AColor;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FCanvas.Font.Color := AColor;
  {$ENDIF}

  FFont.Color := AColor;
  FBlockUpdate := False;
end;

procedure TAdvGraphics.SetFontName(AName: string);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;

  {$IFDEF FMXLIB}
  FCanvas.Font.Name := AName;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FCanvas.Font.Name := AName;
  {$ENDIF}

  FFont.Name := AName;
  FBlockUpdate := False;
end;

procedure TAdvGraphics.SetFont(AFont: TAdvGraphicsFont);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  FCanvas.Font.Assign(AFont);
  FFont.Assign(AFont);
  FBlockUpdate := False;
end;

procedure TAdvGraphics.SetFontStyles(AStyle: TFontStyles);
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  FCanvas.Font.Style := AStyle;
  FFont.Style := AStyle;
  FBlockUpdate := False;
end;

destructor TAdvGraphics.Destroy;
begin
  {$IFDEF NATIVEIOSDRAWING}
  UIGraphicsPopContext;
  FContext := nil;
  if Assigned(FContextGradient) then
  begin
    CFRelease(FContextGradient);
    FContextGradient := nil;
  end;
  {$ENDIF}

  {$IFDEF GDIPLUSDRAWING}
  if Assigned(FGDIPCanvas) then
  begin
    FGDIPCanvas.Free;
    FGDIPCanvas := nil;
  end;
  {$ENDIF}

  FCanvas := nil;

  {$IFDEF FMXLIB}
  if Assigned(FTextLayout) then
  begin
    FTextLayout.Free;
    FTextLayout := nil;
  end;
  {$ENDIF}

  if Assigned(FFont) then
  begin
    FFont.Free;
    FFont := nil;
  end;

  if Assigned(FFill) then
  begin
    FFill.Free;
    FFill := nil;
  end;

  if Assigned(FStroke) then
  begin
    FStroke.Free;
    FStroke := nil;
  end;

  {$IFNDEF LIMITEDGRAPHICSMODE}
  FPictureContainer := nil;
  {$IFDEF CMNLIB}
  FImageList := nil;
  {$ENDIF}
  {$ENDIF}

  if Assigned(FBitmap) then
  begin
    FBitmap.Free;
    FBitmap := nil;
  end;

  inherited;
end;

procedure TAdvGraphics.DrawCloseButton(ARect: TRect; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True);
begin
  DrawCloseButton(ConvertToRectF(ARect), ADown, AFocused, AEnabled, AAdaptToStyle);
end;

procedure TAdvGraphics.DrawCloseButton(ARect: TRectF; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True);
var
  bmp: TAdvBitmap;
  bmpa: TBitmap;
  r: TRectF;
  g: TAdvGraphics;
begin
  DrawButton(ARect, ADown, AFocused, AEnabled, AAdaptToStyle);
  if AAdaptToStyle then
  begin
    bmpa := TBitmap.Create;
    bmpa.SetSize(16, 16);
    {$IFDEF CMNLIB}
    bmpa.TransparentMode := tmFixed;
    bmpa.Transparent := True;
    bmpa.TransparentColor := gcWhite;
    {$ENDIF}
    g := TAdvGraphics.Create(bmpa.Canvas);
    try
      g.BeginScene;
      {$IFDEF CMNLIB}
      g.Fill.Color := gcWhite;
      g.Fill.Kind := gfkSolid;
      g.Stroke.Kind := gskSolid;
      g.Stroke.Color := gcWhite;
      g.DrawRectangle(0, 0, bmpa.Width, bmpa.Height);
      {$ENDIF}
      g.Stroke.Kind := gskSolid;
      g.Stroke.Color := TAdvGraphics.DefaultSelectionFillColor;
      g.Stroke.Width := 2;
      g.DrawLine(PointF(3, 3), PointF(12, 12), gcpmRightDown);
      g.DrawLine(PointF(3, 12), PointF(12, 3), gcpmRightDown);
    finally
      g.EndScene;
      g.Free;
    end;

    try
      r := ARect;
      DrawBitmap(r, bmpa);
    finally
      bmpa.Free;
    end;
  end
  else
  begin
    bmp := TAdvBitmap.CreateFromResource('AdvGRAPHICSCLOSE');

    try
      r := ARect;
      DrawBitmap(r, BitmapToDrawBitmap(bmp));
    finally
      bmp.Free;
    end;
  end;
end;

procedure TAdvGraphics.DrawExpanderButton(ARect: TRect; AState: TAdvGraphicsExpanderState = gesExpanded; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True);
begin
  DrawExpanderButton(ConvertToRectF(ARect), AState, ADown, AFocused, AEnabled, AAdaptToStyle);
end;

procedure TAdvGraphics.DrawExpanderButton(ARect: TRectF; AState: TAdvGraphicsExpanderState = gesExpanded; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True);
var
  bmpa: TBitmap;
  bmp: TAdvBitmap;
  r: TRectF;
  g: TAdvGraphics;
begin
  DrawButton(ARect, ADown, AFocused, AEnabled, AAdaptToStyle);
  bmp := nil;
  if AAdaptToStyle then
  begin
    bmpa := TBitmap.Create;
    bmpa.SetSize(16, 16);
    {$IFDEF CMNLIB}
    bmpa.TransparentMode := tmFixed;
    bmpa.Transparent := True;
    bmpa.TransparentColor := gcWhite;
    {$ENDIF}
    g := TAdvGraphics.Create(bmpa.Canvas);
    try
      g.BeginScene;
      {$IFDEF CMNLIB}
      g.Fill.Color := gcWhite;
      g.Fill.Kind := gfkSolid;
      g.Stroke.Kind := gskSolid;
      g.Stroke.Color := gcWhite;
      g.DrawRectangle(0, 0, bmpa.Width, bmpa.Height);
      {$ENDIF}
      g.Stroke.Kind := gskSolid;
      g.Stroke.Width := 2;
      g.Stroke.Color := TAdvGraphics.DefaultSelectionFillColor;
      case AState of
        gesCollapsed:
        begin
          g.DrawLine(PointF(5, 6), PointF(8, 9), gcpmRightDown);
          g.DrawLine(PointF(8, 9), PointF(11, 6), gcpmRightDown);
        end;
        gesExpanded:
        begin
          g.DrawLine(PointF(5, 9), PointF(8, 6), gcpmRightDown);
          g.DrawLine(PointF(8, 6), PointF(11, 9), gcpmRightDown);
        end;
      end;
    finally
      g.EndScene;
      g.Free;
    end;

    if Assigned(bmpa) then
    begin
      try
        r := ARect;
        DrawBitmap(r, bmpa);
      finally
        bmpa.Free;
      end;
    end;
  end
  else
  begin
    case AState of
      gesCollapsed: bmp := TAdvBitmap.CreateFromResource('AdvGRAPHICSDOWN');
      gesExpanded: bmp := TAdvBitmap.CreateFromResource('AdvGRAPHICSUP');
    end;

    if Assigned(bmp) then
    begin
      try
        r := ARect;
        DrawBitmap(r, BitmapToDrawBitmap(bmp));
      finally
        bmp.Free;
      end;
    end;
  end;
end;

procedure TAdvGraphics.DrawCompactButton(ARect: TRect; AState: TAdvGraphicsCompactState = gcsExpanded; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True);
begin
  DrawCompactButton(ConvertToRectF(ARect), AState, ADown, AFocused, AEnabled, AAdaptToStyle);
end;

procedure TAdvGraphics.DrawCompactButton(ARect: TRectF; AState: TAdvGraphicsCompactState = gcsExpanded; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True);
var
  bmpa: TBitmap;
  bmp: TAdvBitmap;
  r: TRectF;
  g: TAdvGraphics;
begin
  DrawButton(ARect, ADown, AFocused, AEnabled, AAdaptToStyle);
  bmp := nil;
  if AAdaptToStyle then
  begin
    bmpa := TBitmap.Create;
    bmpa.SetSize(16, 16);
    {$IFDEF CMNLIB}
    bmpa.TransparentMode := tmFixed;
    bmpa.Transparent := True;
    bmpa.TransparentColor := gcWhite;
    {$ENDIF}
    g := TAdvGraphics.Create(bmpa.Canvas);
    try
      g.BeginScene;
      {$IFDEF CMNLIB}
      g.Fill.Color := gcWhite;
      g.Fill.Kind := gfkSolid;
      g.Stroke.Kind := gskSolid;
      g.Stroke.Color := gcWhite;
      g.DrawRectangle(0, 0, bmpa.Width, bmpa.Height);
      {$ENDIF}
      g.Stroke.Kind := gskSolid;
      g.Stroke.Width := 2;
      g.Stroke.Color := TAdvGraphics.DefaultSelectionFillColor;
      case AState of
        gcsCollapsed:
        begin
          g.DrawLine(PointF(6, 5), PointF(9, 8), gcpmRightDown);
          g.DrawLine(PointF(9, 8), PointF(6, 11), gcpmRightDown);
        end;
        gcsExpanded:
        begin
          g.DrawLine(PointF(9, 5), PointF(6, 8), gcpmRightDown);
          g.DrawLine(PointF(6, 8), PointF(9, 11), gcpmRightDown);
        end;
      end;
    finally
      g.EndScene;
      g.Free;
    end;

    if Assigned(bmpa) then
    begin
      try
        r := ARect;
        DrawBitmap(r, bmpa);
      finally
        bmpa.Free;
      end;
    end;
  end
  else
  begin
    case AState of
      gcsCollapsed: bmp := TAdvBitmap.CreateFromResource('AdvGRAPHICSRIGHT');
      gcsExpanded: bmp := TAdvBitmap.CreateFromResource('AdvGRAPHICSLEFT');
    end;

    if Assigned(bmp) then
    begin
      try
        r := ARect;
        DrawBitmap(r, BitmapToDrawBitmap(bmp));
      finally
        bmp.Free;
      end;
    end;
  end;
end;

procedure TAdvGraphics.DrawDropDownButton(ARect: TRect; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; ACenter: Boolean = False; AAdaptToStyle: Boolean = True);
begin
  DrawDropDownButton(ConvertToRectF(ARect), ADown, AFocused, AEnabled, ACenter, AAdaptToStyle);
end;

procedure TAdvGraphics.DrawDropDownButton(ARect: TRectF; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; ACenter: Boolean = False; AAdaptToStyle: Boolean = True);
var
  bmp: TAdvBitmap;
  bmpa: TBitmap;
  r: TRectF;
  g: TAdvGraphics;
begin
  DrawButton(ARect, ADown, AFocused, AEnabled, AAdaptToStyle);
  if AAdaptToStyle then
  begin
    bmpa := TBitmap.Create;
    bmpa.SetSize(7, 7);
    {$IFDEF CMNLIB}
    bmpa.TransparentMode := tmFixed;
    bmpa.Transparent := True;
    bmpa.TransparentColor := gcWhite;
    {$ENDIF}
    g := TAdvGraphics.Create(bmpa.Canvas);
    try
      g.BeginScene;
      {$IFDEF CMNLIB}
      g.Fill.Color := gcWhite;
      g.Fill.Kind := gfkSolid;
      g.Stroke.Kind := gskSolid;
      g.Stroke.Color := gcWhite;
      g.DrawRectangle(0, 0, bmpa.Width, bmpa.Height);
      {$ENDIF}
      g.Stroke.Kind := gskSolid;
      g.Stroke.Color := TAdvGraphics.DefaultSelectionFillColor;
      g.DrawLine(PointF(0, 1), PointF(6, 1), gcpmRightDown);
      g.DrawLine(PointF(0, 2), PointF(6, 2), gcpmRightDown);
      g.DrawLine(PointF(1, 3), PointF(5, 3), gcpmRightDown);
      g.DrawLine(PointF(2, 4), PointF(4, 4), gcpmRightDown);
      g.DrawLine(PointF(3, 5), PointF(3, 5), gcpmRightDown);
    finally
      g.EndScene;
      g.Free;
    end;

    try
      if (ARect.Right - bmpa.Width - 10 > ARect.Left) and not ACenter then
        r := RectF(ARect.Right - bmpa.Width - 10, ARect.Top, ARect.Right, ARect.Bottom)
      else
        r := ARect;

      DrawBitmap(r, bmpa);
    finally
      bmpa.Free;
    end;
  end
  else
  begin
    bmp := TAdvBitmap.CreateFromResource('AdvGRAPHICSEXPAND');
    try
      if (ARect.Right - bmp.Width - 10 > ARect.Left) and not ACenter then
        r := RectF(ARect.Right - bmp.Width - 10, ARect.Top, ARect.Right, ARect.Bottom)
      else
        r := ARect;

      DrawBitmap(r, BitmapToDrawBitmap(bmp));
    finally
      bmp.Free;
    end;
  end;
end;

procedure TAdvGraphics.DrawButton(ARect: TRect; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True);
begin
  DrawButton(ConvertToRectF(ARect), ADown, AFocused, AEnabled, AAdaptToStyle);
end;

procedure TAdvGraphics.DrawButton(ARect: TRectF; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True; AAdaptToStyle: Boolean = True);
var
  r: TRectF;
begin
  r := ARect;
  Stroke.Kind := gskSolid;
  Stroke.Width := 1;
  Fill.Kind := gfkSolid;

  if AAdaptToStyle then
  begin
    if AEnabled then
    begin
      if not AFocused then
      begin
        Stroke.Color := TAdvGraphics.DefaultButtonStrokeColor;
        Fill.Color := TAdvGraphics.DefaultButtonFillColor;
      end
      else
      begin
        Stroke.Color := TAdvGraphics.DefaultButtonStrokeColorFocused;
        Fill.Color := TAdvGraphics.DefaultButtonFillColorFocused;
      end;
    end
    else
    begin
      Stroke.Color := TAdvGraphics.DefaultButtonStrokeColorDisabled;
      Fill.Color := TAdvGraphics.DefaultButtonFillColorDisabled;
    end;
  end
  else
  begin
    if AEnabled then
    begin
      if not AFocused then
      begin
        Stroke.Color := gcDarkGray;
        Fill.Color := MakeGraphicsColor(225, 225, 225);
      end
      else
      begin
        Stroke.Color := MakeGraphicsColor(60, 127, 177);
        Fill.Color := MakeGraphicsColor(229, 241, 251);
      end;
    end
    else
    begin
      Stroke.Color := gcDarkGray;
      Fill.Color := gcLightgray;
    end;
  end;

  DrawRectangle(r);
  InflateRectEx(r, -1, -1);
  Fill.Kind := gfkNone;

  if not ADown then
    Stroke.Color := Fill.Color
  else
    Stroke.Color := Lighter(Stroke.Color, 40);

  DrawRectangle(r);
end;

procedure TAdvGraphics.DrawCheckBox(ARect: TRect; AChecked: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True);
begin
  DrawCheckBox(ConvertToRectF(ARect), AChecked, AFocused, AEnabled);
end;

procedure TAdvGraphics.DrawCheckBox(ARect: TRectF; AChecked: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True);
var
  c: TAdvGraphicsColor;
  r: TRectF;
begin
  r := ARect;
  InflateRectEx(r, -1, -1);

  if AEnabled then
  begin
    if AFocused then
      c := gcSteelBlue
    else
      c := gcBlack;
  end
  else
    c := gcDarkgray;

  Fill.Kind := gfkSolid;
  if AEnabled then
    Fill.Color := Lighter(gcLightgray, 85)
  else
    Fill.Color := gcLightgray;

  Stroke.Width := 1;
  Stroke.Kind := gskSolid;
  Stroke.Color := c;
  DrawRectangle(r);
  InflateRectEx(r, -r.Width / 5, -r.Height / 5);
  Stroke.Width := 2;
  Stroke.Color := c;
  if AChecked then
  begin
    {$IFDEF FMXLIB}
    DrawLine(PointF(r.Left + 1, r.Top + 1), PointF(r.Right - 1, r.Bottom - 1));
    DrawLine(PointF(r.Right - 1, r.Top + 1), PointF(r.Left + 1, r.Bottom - 1));
    {$ENDIF}
    {$IFDEF CMNLIB}
    DrawLine(PointF(r.Left, r.Top), PointF(r.Right - 1, r.Bottom - 1));
    DrawLine(PointF(r.Right - 1, r.Top), PointF(r.Left, r.Bottom - 1));
    {$ENDIF}
  end;
end;

procedure TAdvGraphics.DrawProgressBar(ARect: TRect; AValue: Single; AFormat: string = '%.0f%%'; AMax: Single = 100; AColor: TAdvGraphicsColor = gcYellowgreen; ATextColor: TAdvGraphicsColor = gcBlack; AShowText: Boolean = True; AEnabled: Boolean = True);
begin
  DrawProgressBar(ConvertToRectF(ARect), AValue, AFormat, AMax, AColor, ATextColor, AShowText, AEnabled);
end;

procedure TAdvGraphics.DrawProgressBar(ARect: TRectF; AValue: Single; AFormat: string = '%.0f%%'; AMax: Single = 100; AColor: TAdvGraphicsColor = gcYellowgreen; ATextColor: TAdvGraphicsColor = gcBlack; AShowText: Boolean = True; AEnabled: Boolean = True);
var
  r, rp: TRectF;
  v: Single;
begin
  r := ARect;
  rp := r;
  if AEnabled then
    Fill.Color := Lighter(gcLightGray, 75)
  else
    Fill.Color := gcLightGray;

  Fill.Kind := gfkSolid;
  Stroke.Kind := gskSolid;
  Stroke.Color := gcDarkgray;

  DrawRectangle(r);

  v := Max(0, Min(AValue, AMax));

  if (v >= 0) and (v <= AMax) and (AMax > 0) then
  begin
    InflateRectEx(rp, -1, -1);
    rp.Width := rp.Width * v / AMax;

    Fill.Color := AColor;
    Stroke.Color := Fill.Color;

    DrawRectangle(rp);

    if AShowText then
    begin
      Font.Color := ATextColor;
      DrawText(r, Format(AFormat, [v / AMax * 100]), False, gtaCenter, gtaCenter);
    end;
  end;
end;

procedure TAdvGraphics.DrawRadioButton(ARect: TRect; AChecked: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True);
begin
  DrawRadioButton(ConvertToRectF(ARect), AChecked, AFocused, AEnabled);
end;

procedure TAdvGraphics.DrawRadioButton(ARect: TRectF; AChecked: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True);
var
  c: TAdvGraphicsColor;
  r: TRectF;
begin
  r := ARect;
  InflateRectEx(r, -1, -1);

  if AEnabled then
  begin
    if AFocused then
      c := gcSteelBlue
    else
      c := gcBlack;
  end
  else
    c := gcDarkgray;

  Fill.Kind := gfkSolid;
  if AEnabled then
    Fill.Color := Lighter(gcLightgray, 85)
  else
    Fill.Color := gcLightgray;

  Stroke.Kind := gskSolid;
  Stroke.Width := 1;
  Stroke.Color := c;
  DrawEllipse(r);
  InflateRectEx(r, -r.Width / 5, -r.Height / 5);
  Fill.Kind := gfkSolid;
  Fill.Color := c;
  if AChecked then
  begin
    DrawEllipse(r);
  end;
end;

{$IFDEF CMNLIB}
procedure TAdvGraphics.DrawBitmap(ALeft, ATop: Single; ABitmap: TAdvBitmap);
begin
  DrawBitmap(ALeft, ATop, BitmapToDrawBitmap(ABitmap));
end;

procedure TAdvGraphics.DrawBitmap(ALeft, ATop: Integer; ABitmap: TAdvBitmap);
begin
  DrawBitmap(ALeft, ATop, BitmapToDrawBitmap(ABitmap));
end;
{$ENDIF}

procedure TAdvGraphics.DrawBitmap(ALeft, ATop: Single; ABitmap: TAdvDrawBitmap);
begin
  DrawBitmap(RectF(ALeft, ATop, ALeft + ABitmap.Width, ATop + ABitmap.Height), ABitmap);
end;

procedure TAdvGraphics.DrawBitmap(ALeft, ATop: Integer; ABitmap: TAdvDrawBitmap);
begin
  DrawBitmap(Rect(ALeft, ATop, ALeft + ABitmap.Width, ATop + ABitmap.Height), ABitmap);
end;

procedure TAdvGraphics.DrawBitmap(ARect: TRect; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
  AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
begin
  DrawBitmap(ConvertToRectF(ARect), ABitmap, AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawBitmap(ARect: TRectF; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
  AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
begin
  DrawBitmap(ARect.Left, ARect.Top, ARect.Right, ARect.Bottom, ABitmap, AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawBitmap(ALeft: Integer; ATop: Integer; ARight: Integer; ABottom: Integer; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
  AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
begin
  DrawBitmap(RectF(ALeft, ATop, ARight, ABottom), ABitmap, AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawBitmap(ALeft: Double; ATop: Double; ARight: Double; ABottom: Double; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
  AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
var
  r: TRectF;
  {$IFDEF GDIPLUSDRAWING}
  img: TGPImage;

  function CreateGPImage: TGPImage;
  var
    pstm: IStream;
    pcbWrite: Longint;
    aSize: Int64;
    TempImage: TGPImage;
    TempGraphics: TGPGraphics;
    hglobal: THandle;
    DataStream: TMemoryStream;
  begin
    Result := nil;
    DataStream := TMemoryStream.Create;
    ABitmap.SaveToStream(DataStream);
    try
      DataStream.Position := 0;

      hglobal := GlobalAlloc(GMEM_MOVEABLE, DataStream.Size);
      if (hglobal = 0) then
        raise Exception.Create('Could not allocate memory for image');
      try

        pstm := nil;
        // Create IStream* from global memory
        CreateStreamOnHGlobal(hglobal, TRUE, pstm);
    {$WARNINGS OFF}
        pstm.Write(DataStream.Memory, DataStream.Size, @pcbWrite);
    {$WARNINGS ON}
        pstm.Seek(0, STREAM_SEEK_SET, aSize);

        TempImage := TGPImage.Create(pstm);
        if TempImage.GetType = ImageTypeBitmap then
        begin
          Result := TGPBitmap.Create(TempImage.GetWidth, TempImage.GetHeight,
            PixelFormat32bppARGB);
          TempGraphics := TGPGraphics.Create(Result);
          TempGraphics.DrawImage(TempImage, 0, 0, TempImage.GetWidth,
            TempImage.GetHeight);
          TempGraphics.Free;
          TempImage.Free;
        end
        else
          Result := TempImage;

      finally
        GlobalFree(hglobal);
      end;
    finally
      DataStream.Free;
    end;
  end;
  {$ENDIF}
begin
  if not Assigned(ABitmap) then
    Exit;

  r := RectF(ALeft, ATop, ARight, ABottom);
  r := GetBitmapDrawRectangle(r, ABitmap, AAspectRatio, AStretch, ACenter, ACropping);
  {$IFDEF FMXLIB}
  FCanvas.DrawBitmap(ABitmap, RectF(0, 0, ABitmap.Width, ABitmap.Height), r, 1, True);
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  img := CreateGPImage;
  try
    FGDIPCanvas.DrawImage(img, MakeRect(r.Left, r.Top, r.Width, r.Height));
  finally
    img.Free;
  end;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  FCanvas.StretchDraw(Bounds(Round(r.Left), Round(r.Top), Round(r.Width), Round(r.Height)), ABitmap);
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.DrawBitmapPart(ASourceRect: TRect; ADestinationRect: TRect; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
  AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
begin
  DrawBitmapPart(ConvertToRectF(ASourceRect), ConvertToRectF(ADestinationRect), ABitmap, AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawBitmapPart(ASourceRect: TRectF; ADestinationRect: TRectF; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True;
  AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
begin
  DrawBitmapPart(ASourceRect.Left, ASourceRect.Top, ASourceRect.Right, ASourceRect.Bottom, ADestinationRect.Left, ADestinationRect.Top, ADestinationRect.Right, ADestinationRect.Bottom,
    ABitmap, AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawBitmapPart(ASourceLeft: Integer; ASourceTop: Integer; ASourceRight: Integer; ASourceBottom: Integer; ADestinationLeft: Integer; ADestinationTop: Integer;
  ADestinationRight: Integer; ADestinationBottom: Integer; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True; AStretch: Boolean = False;
  ACenter: Boolean = True; ACropping: Boolean = False);
begin
  DrawBitmapPart(RectF(ASourceLeft, ASourceTop, ASourceRight, ASourceBottom), RectF(ADestinationLeft, ADestinationTop, ADestinationRight, ADestinationBottom), ABitmap, AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawBitmapPart(ASourceLeft: Double; ASourceTop: Double; ASourceRight: Double; ASourceBottom: Double; ADestinationLeft: Double; ADestinationTop: Double;
  ADestinationRight: Double; ADestinationBottom: Double; ABitmap: TAdvDrawBitmap; AAspectRatio: Boolean = True; AStretch: Boolean = False;
  ACenter: Boolean = True; ACropping: Boolean = False);
var
  r: TRectF;
  g: TAdvGraphics;
begin
  r := RectF(ADestinationLeft, ADestinationTop, ADestinationRight, ADestinationBottom);
  g := TAdvGraphics.CreateBitmapCanvas(Round(ASourceRight - ASourceLeft), Round(ASourceBottom - ASourceTop));
  try
    g.BeginScene;
    g.DrawBitmap(-ASourceLeft, -ASourceTop, -ASourceLeft + g.Bitmap.Width, -ASourceTop + g.Bitmap.Height, ABitmap, False, False, False, False);
    g.EndScene;
    DrawBitmap(r, g.Bitmap, AAspectRatio, AStretch, ACenter, ACropping);
  finally
    g.Free;
  end;
end;

class procedure TAdvGraphics.GetAspectSize(var AWidth: Single; var AHeight: Single; AOriginalWidth: Single; AOriginalHeight: Single; ANewWidth: Single; ANewHeight: Single;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACropping: Boolean = False);
var
  arc, ar: Single;
begin
  if AAspectRatio then
  begin
    if (AOriginalWidth > 0) and (AOriginalHeight > 0) and (ANewWidth > 0) and (ANewHeight > 0) then
    begin
      if (AOriginalWidth < ANewWidth) and (AOriginalHeight < ANewHeight) and (not AStretch) then
      begin
        AWidth := AOriginalWidth;
        AHeight := AOriginalHeight;
      end
      else
      begin
        if AOriginalWidth / AOriginalHeight < ANewWidth / ANewHeight then
        begin
          AHeight := ANewHeight;
          AWidth := ANewHeight * AOriginalWidth / AOriginalHeight;
        end
        else
        begin
          AWidth := ANewWidth;
          AHeight := ANewWidth * AOriginalHeight / AOriginalWidth;
        end;
      end;
    end
    else
    begin
      AWidth := 0;
      AHeight := 0;
    end;
  end
  else
  begin
    if AStretch then
    begin
      AWidth := ANewWidth;
      AHeight := ANewHeight;
    end
    else
    begin
      AWidth := AOriginalWidth;
      AHeight := AOriginalHeight;

      if ACropping then
      begin
        if (AWidth >= AHeight) and (AWidth > 0) then
        begin
          AHeight := AOriginalWidth / AWidth * AHeight;
          AWidth := AOriginalWidth;
        end
        else
        if (AHeight >= AWidth) and (AHeight > 0) then
        begin
          AWidth := AOriginalHeight / AHeight * AWidth;
          AHeight := AOriginalHeight;
        end;

        if AHeight = 0 then
          ar := 1
        else
          ar := AWidth / AHeight;

        if AOriginalHeight = 0 then
          arc := 1
        else
          arc := AOriginalWidth / AOriginalHeight;

        if (ar < 1) or (arc > ar) then
        begin
          AHeight := AOriginalWidth / ar;
          AWidth := AOriginalWidth;
        end
        else
        begin
          AWidth := ar * AOriginalHeight;
          AHeight := AOriginalHeight;
        end;
      end;
    end;
  end;
end;

function TAdvGraphics.GetBitmapDrawRectangle(ALeft: Integer; ATop: Integer; ARight: Integer; ABottom: Integer; ABitmap: TAdvDrawBitmap;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False): TRect;
begin
  Result := ConvertToRect(GetBitmapDrawRectangle(RectF(ALeft, ATop, ARight, ABottom), ABitmap, AAspectRatio, AStretch, ACenter, ACropping));
end;

function TAdvGraphics.GetBitmapDrawRectangle(ALeft: Double; ATop: Double; ARight: Double; ABottom: Double; ABitmap: TAdvDrawBitmap;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False): TRectF;
var
  bmp: TAdvDrawBitmap;
  rdest: TRectF;
  w, h: Single;
  x, y: Single;
begin
  Result := RectF(0, 0, 0, 0);
  bmp := ABitmap;
  if Assigned(bmp) then
  begin
    x := 0;
    y := 0;
    w := 0;
    h := 0;
    GetAspectSize(w, h, bmp.Width, bmp.Height, ARight - ALeft, ABottom - ATop, AAspectRatio, AStretch, ACropping);
    if ACenter or ACropping then
    begin
      x := Round((ARight - ALeft - w) / 2);
      y := Round((ABottom - ATop - h) / 2);
    end;

    rdest := RectF(ALeft + x, ATop + y, ALeft + x + w, ATop + y + h);
    Result := rdest;
  end;
end;

function TAdvGraphics.GetBitmapDrawRectangle(ARect: TRect; ABitmap: TAdvDrawBitmap;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False): TRect;
begin
  Result := ConvertToRect(GetBitmapDrawRectangle(ConvertToRectF(ARect), ABitmap, AAspectRatio, AStretch, ACenter, ACropping));
end;

function TAdvGraphics.GetBitmapDrawRectangle(ARect: TRectF; ABitmap: TAdvDrawBitmap;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False): TRectF;
begin
  Result := GetBitmapDrawRectangle(ARect.Left, ARect.Top, ARect.Right, ARect.Bottom, ABitmap, AAspectRatio, AStretch, ACenter, ACropping);
end;

{$IFNDEF LIMITEDGRAPHICSMODE}
class function TAdvGraphics.GetScaledBitmap(ABitmaps: TAdvScaledBitmaps; AScale: Single = 0; APictureContainer: TPictureContainer = nil): TAdvBitmap;
var
  b: TAdvScaledBitmap;
  bmp: TAdvBitmap;
begin
  Result := nil;
  if Assigned(ABitmaps) then
  begin
    if AScale > 0 then
      b := ABitmaps.GetItemByScale(AScale)
    else
      b := ABitmaps.GetItemByScale(TAdvUtils.GetDPIScale);

    if Assigned(b) then
    begin
      if Assigned(b.Bitmap) and not IsBitmapEmpty(b.Bitmap) then
        Result := b.Bitmap
      else
      begin
        bmp := GetBitmapFromPictureContainer(APictureContainer, b.BitmapName, True, AScale);
        if Assigned(bmp) and not IsBitmapEmpty(bmp) then
          Result := bmp
        else
        begin
          bmp := GetBitmapFromPictureContainer(APictureContainer, b.BitmapName, False);
          if Assigned(bmp) and not IsBitmapEmpty(bmp) then
            Result := bmp
        end;
      end;
    end;
  end;
end;

class function TAdvGraphics.ApplyHilight(AText: string; AHilight: string; ATag: string; ADoCase: Boolean): String;
begin
  Result := HiLight(AText, AHilight, ATag, ADoCase);
end;

class function TAdvGraphics.GetBitmapFromPictureContainer(APictureContainer: TPictureContainer; AName: string; AApplyScale: Boolean = False; AScale: Single = 0): TAdvBitmap;
begin
  Result := nil;
  if Assigned(APictureContainer) and (AName <> '') then
  begin
    if AApplyScale then
    begin
      if AScale > 0 then
        Result := APictureContainer.FindBitmap(AName + '_' + FloatToStr(AScale))
      else
        Result := APictureContainer.FindBitmap(AName + '_' + FloatToStr(TAdvUtils.GetDPIScale));
    end;

    if not Assigned(Result) then
      Result := APictureContainer.FindBitmap(AName);
  end;
end;

procedure TAdvGraphics.DrawBitmapWithName(ARect: TRect; ABitmapName: string; AApplyScale: Boolean = False; AScale: Single = 0;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
begin
  DrawBitmapWithName(ConvertToRectF(ARect), ABitmapName, AApplyScale, AScale, AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawBitmapWithName(ARect: TRectF; ABitmapName: string; AApplyScale: Boolean = False; AScale: Single = 0;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
var
  b: TAdvBitmap;
begin
  b := GetBitmapFromPictureContainer(FPictureContainer, ABitmapName, AApplyScale, AScale);
  if Assigned(b) then
    DrawBitmap(ARect, BitmapToDrawBitmap(b), AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawBitmapWithName(ALeft: Integer; ATop: Integer; ARight: Integer; ABottom: Integer; ABitmapName: string;
  AApplyScale: Boolean = False; AScale: Single = 0; AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True;
  ACropping: Boolean = False);
begin
  DrawBitmapWithName(RectF(ALeft, ATop, ARight, ABottom), ABitmapName, AApplyScale, AScale, AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawBitmapWithName(ALeft: Double; ATop: Double; ARight: Double; ABottom: Double; ABitmapName: string;
  AApplyScale: Boolean = False; AScale: Single = 0; AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True;
  ACropping: Boolean = False);
var
  b: TAdvBitmap;
begin
  b := GetBitmapFromPictureContainer(FPictureContainer, ABitmapName, AApplyScale, AScale);
  if Assigned(b) then
    DrawBitmap(ALeft, ATop, ARight, ABottom, BitmapToDrawBitmap(b), AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawScaledBitmap(ARect: TRect; ABitmaps: TAdvScaledBitmaps; AScale: Single = 0;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
begin
  DrawScaledBitmap(ConvertToRectF(ARect), ABitmaps, AScale, AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawScaledBitmap(ARect: TRectF; ABitmaps: TAdvScaledBitmaps; AScale: Single = 0;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
var
  b: TAdvScaledBitmap;
  bmp: TAdvBitmap;
begin
  if Assigned(ABitmaps) then
  begin
    if AScale > 0 then
      b := ABitmaps.GetItemByScale(AScale)
    else
      b := ABitmaps.GetItemByScale(TAdvUtils.GetDPIScale);

    if Assigned(b) then
    begin
      if Assigned(b.Bitmap) and not IsBitmapEmpty(b.Bitmap) then
        DrawBitmap(ARect, BitmapToDrawBitmap(b.Bitmap), AAspectRatio, AStretch, ACenter, ACropping)
      else
      begin
        bmp := GetBitmapFromPictureContainer(FPictureContainer, b.BitmapName, True, AScale);
        if Assigned(bmp) and not IsBitmapEmpty(bmp) then
          DrawBitmap(ARect, BitmapToDrawBitmap(bmp), AAspectRatio, AStretch, ACenter, ACropping)
        else
          DrawBitmapWithName(ARect, b.BitmapName, False, b.Scale, AAspectRatio, AStretch, ACenter, ACropping);
      end;
    end;
  end;
end;

procedure TAdvGraphics.DrawScaledBitmap(ALeft: Integer; ATop: Integer; ARight: Integer; ABottom: Integer; ABitmaps: TAdvScaledBitmaps; AScale: Single = 0;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
begin
  DrawScaledBitmap(RectF(ALeft, ATop, ARight, ABottom), ABitmaps, AScale, AAspectRatio, AStretch, ACenter, ACropping);
end;

procedure TAdvGraphics.DrawScaledBitmap(ALeft: Double; ATop: Double; ARight: Double; ABottom: Double; ABitmaps: TAdvScaledBitmaps; AScale: Single = 0;
  AAspectRatio: Boolean = True; AStretch: Boolean = False; ACenter: Boolean = True; ACropping: Boolean = False);
var
  b: TAdvScaledBitmap;
  bmp: TAdvBitmap;
begin
  if Assigned(ABitmaps) then
  begin
    if AScale > 0 then
      b := ABitmaps.GetItemByScale(AScale)
    else
      b := ABitmaps.GetItemByScale(TAdvUtils.GetDPIScale);

    if Assigned(b) then
    begin
      if Assigned(b.Bitmap) and not IsBitmapEmpty(b.Bitmap) then
        DrawBitmap(ALeft, ATop, ARight, ABottom, BitmapToDrawBitmap(b.Bitmap), AAspectRatio, AStretch, ACenter, ACropping)
      else
      begin
        bmp := GetBitmapFromPictureContainer(FPictureContainer, b.BitmapName, True, AScale);
        if Assigned(bmp) and not IsBitmapEmpty(bmp) then
          DrawBitmap(ALeft, ATop, ARight, ABottom, BitmapToDrawBitmap(bmp), AAspectRatio, AStretch, ACenter, ACropping)
        else
          DrawBitmapWithName(ALeft, ATop, ARight, ABottom, b.BitmapName, False, b.Scale, AAspectRatio, AStretch, ACenter, ACropping);
      end;
    end;
  end;
end;
{$ENDIF}

procedure TAdvGraphics.ClipRect(ARect: TRect);
begin
  ClipRect(ConvertToRect(ARect));
end;

procedure TAdvGraphics.ClipRect(ARect: TRectF);
begin
  {$IFDEF FMXLIB}
  FCanvas.IntersectClipRect(ARect);
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  FGDIPCanvas.SetClip(MakeRect(ARect.Left, ARect.Top, ARect.Width, ARect.Height));
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  {$IFDEF VCLLIB}
  IntersectClipRect(FCanvas.Handle, Round(ARect.Left), Round(ARect.Top), Round(ARect.Right), Round(ARect.Bottom));
  {$ENDIF}
  {$IFDEF LCLLIB}
  FCanvas.Clipping := True;
  FCanvas.ClipRect := Rect(Round(ARect.Left), Round(ARect.Top), Round(ARect.Right), Round(ARect.Bottom));
  {$ENDIF}
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.DrawFocusPath(APath: TAdvGraphicsPath; AColor: TAdvGraphicsColor = gcBlack);
{$IFDEF CMNLIB}
var
  {$IFDEF GDIPLUSDRAWING}
  stk: TAdvGraphicsStrokeKind;
  stc: TAdvGraphicsColor;
  smt: SmoothingMode;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  bs: TBrushStyle;
  c: TAdvGraphicsColor;
  {$ENDIF}
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  FCanvas.Stroke.Kind := TBrushKind.Solid;
  FCanvas.Stroke.Color := AColor;
  FCanvas.StrokeDash := TStrokeDash.Dot;
  DrawPath(APath);
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  smt := FGDIPCanvas.GetSmoothingMode;
  FGDIPCanvas.SetSmoothingMode(SmoothingModeDefault);
  stk := Stroke.Kind;
  stc := Stroke.Color;
  Stroke.Kind := gskDot;
  Stroke.Color := AColor;
  DrawPath(APath);
  Stroke.Kind := stk;
  Stroke.Color := stc;
  FGDIPCanvas.SetSmoothingMode(smt);
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  c := FCanvas.Brush.Color;
  bs := FCanvas.Brush.Style;
  FCanvas.Brush.Style := bsClear;
  FCanvas.Pen.Color := AColor;
  StartSpecialPen;
  DrawPath(APath);
  StopSpecialPen;
  FCanvas.Brush.Color := c;
  FCanvas.Brush.Style := bs;
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.DrawFocusRectangle(ALeft: Integer; ATop: Integer; ARight: Integer; ABottom: Integer; AColor: TAdvGraphicsColor = gcBlack; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawFocusRectangle(Rect(ALeft, ATop, ARight, ABottom), AColor, AModifyRectMode);
end;

procedure TAdvGraphics.DrawFocusRectangle(ALeft: Double; ATop: Double; ARight: Double; ABottom: Double; AColor: TAdvGraphicsColor = gcBlack; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
var
{$IFDEF FMXLIB}
  r: TRectF;
{$ENDIF}
{$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  r: TGPRectF;
  p: TGPPen;
  smt: SmoothingMode;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  r: TRect;
  c: TAdvGraphicsColor;
  bs: TBrushStyle;
  {$ENDIF}
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  r := RectF(ALeft, ATop, ARight, ABottom);
  r := ModifyRect(r, AModifyRectMode);

  FCanvas.Stroke.Thickness := 1;
  FCanvas.Stroke.Kind := TBrushKind.Solid;
  FCanvas.Stroke.Color := AColor;
  FCanvas.StrokeDash := TStrokeDash.Dot;
  FCanvas.DrawRect(r, 0, 0, AllCorners, 1);
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  r := MakeRect(ALeft, ATop, ARight - ALeft, ABottom - ATop);
  p := CreateGDIPStroke(Stroke);
  try
    smt := FGDIPCanvas.GetSmoothingMode;
    FGDIPCanvas.SetSmoothingMode(SmoothingModeDefault);
    p.SetDashStyle(DashStyleDot);
    p.SetWidth(1);
    p.SetColor(ConvertToGDIPColor(AColor));
    FGDIPCanvas.DrawRectangle(p, r);
    FGDIPCanvas.SetSmoothingMode(smt);
  finally
    p.Free;
  end;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  r := Rect(Round(ALeft), Round(ATop), Round(ARight), Round(ABottom));
  c := FCanvas.Brush.Color;
  bs := FCanvas.Brush.Style;
  FCanvas.Brush.Style := bsClear;
  FCanvas.Pen.Color := AColor;
  StartSpecialPen;
  FCanvas.Rectangle(r);
  StopSpecialPen;
  FCanvas.Brush.Color := c;
  FCanvas.Brush.Style := bs;
  {$ENDIF}
  {$ENDIF}
end;

procedure TAdvGraphics.DrawFocusRectangle(ARect: TRect; AColor: TAdvGraphicsColor = gcBlack; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawFocusRectangle(ConvertToRectF(ARect), AColor, AModifyRectMode);
end;

procedure TAdvGraphics.DrawFocusRectangle(ARect: TRectF; AColor: TAdvGraphicsColor = gcBlack; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawFocusRectangle(ARect.Left, ARect.Top, ARect.Right, ARect.Bottom, AColor, AModifyRectMode);
end;

procedure TAdvGraphics.FontChanged(Sender: TObject);
begin
  SetFont(Sender as TAdvGraphicsFont);
end;

procedure TAdvGraphics.StrokeChanged(Sender: TObject);
begin
  SetStroke(Sender as TAdvGraphicsStroke);
end;

procedure TAdvGraphics.FillChanged(Sender: TObject);
begin
  SetFill(Sender as TAdvGraphicsFill);
end;

{$IFDEF CMNLIB}
procedure TAdvGraphics.DrawRotatedText(ACanvas: TCanvas; ARect: TRect; AText: String; AAngle: Single; AHorizontalAlign, AVerticalAlign: TAdvGraphicsTextAlign);
var
  tw, th: Integer;
  so: Integer;
  s: String;
  xs, ys, angle: Single;
begin
  s := AText;
  so := ACanvas.Font.Orientation;
  angle := -10 * AAngle;
  ACanvas.Font.Orientation := Round(angle);
  xs := ARect.Left;
  ys := ARect.Top;
  tw := ACanvas.TextWidth(s);
  th := ACanvas.TextHeight(s);

  if angle < 0 then
  begin
    case AHorizontalAlign of
      gtaCenter: ys := ys + (ARect.Bottom - ARect.Top - tw) / 2;
      gtaTrailing: ys := ys + (ARect.Bottom - ARect.Top - tw);
    end;

    case AVerticalAlign of
      gtaCenter: xs := xs + (ARect.Right - ARect.Left) / 2 + th / 2;
      gtaLeading: xs := xs + (ARect.Right - ARect.Left);
      gtaTrailing: xs := xs + th;
    end;
  end
  else
  begin
    case AHorizontalAlign of
      gtaCenter: ys := ys + (ARect.Bottom - ARect.Top - tw) / 2 + tw;
      gtaLeading: ys := ys + (ARect.Bottom - ARect.Top);
      gtaTrailing: ys := ys + tw;
    end;

    case AVerticalAlign of
      gtaCenter: xs := xs + (ARect.Right - ARect.Left) / 2 - th / 2;
      gtaTrailing: xs := xs + (ARect.Right - ARect.Left - th);
    end;
  end;

  ACanvas.TextOut(Round(xs), Round(ys), s);
  ACanvas.Font.Orientation := so;
end;
{$ENDIF}

function TAdvGraphics.DrawText(ALeft, ATop, ARight, ABottom: Integer; AText: String; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading;
  AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
  AMinWidth: Single = -1; AMinHeight: Single = -1{$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String;
var
  AControlID, AControlValue, AControlType: string;
begin
  AControlID := '';
  AControlValue := '';
  AControlType := '';
  Result := DrawText(RectF(ALeft, ATop, ARight, ABottom), AText, AControlID, AControlValue, AControlType, AWordWrapping, AHorizontalAlign, AVerticalAlign, ATrimming,
    AAngle, AMinWidth, AMinHeight{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML, ATestAnchor, AX, AY{$ENDIF});
end;

function TAdvGraphics.DrawText(ALeft, ATop, ARight, ABottom: Double; AText: String; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading;
  AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
  AMinWidth: Single = -1; AMinHeight: Single = -1{$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String;
var
  AControlID, AControlValue, AControlType: string;
begin
  AControlID := '';
  AControlValue := '';
  AControlType := '';
  Result := DrawText(RectF(ALeft, ATop, ARight, ABottom), AText, AControlID, AControlValue, AControlType, AWordWrapping, AHorizontalAlign, AVerticalAlign, ATrimming,
    AAngle, AMinWidth, AMinHeight{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML, ATestAnchor, AX, AY{$ENDIF});
end;

function TAdvGraphics.DrawText(ALeft, ATop, ARight, ABottom: Integer; AText: String; var AControlID: string; var AControlValue: string; var AControlType: string; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading;
  AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
  AMinWidth: Single = -1; AMinHeight: Single = -1{$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String;
begin
  Result := DrawText(RectF(ALeft, ATop, ARight, ABottom), AText, AControlID, AControlValue, AControlType, AWordWrapping, AHorizontalAlign, AVerticalAlign, ATrimming,
    AAngle, AMinWidth, AMinHeight{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML, ATestAnchor, AX, AY{$ENDIF});
end;

function TAdvGraphics.DrawText(ALeft, ATop, ARight, ABottom: Double; AText: String; var AControlID: string; var AControlValue: string; var AControlType: string; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading;
  AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
  AMinWidth: Single = -1; AMinHeight: Single = -1{$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String;
begin
  Result := DrawText(RectF(ALeft, ATop, ARight, ABottom), AText, AControlID, AControlValue, AControlType, AWordWrapping, AHorizontalAlign, AVerticalAlign, ATrimming,
    AAngle, AMinWidth, AMinHeight{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML, ATestAnchor, AX, AY{$ENDIF});
end;


procedure TAdvGraphics.InitializeDefaultAppearance;
begin
  {$IFNDEF LIMITEDGRAPHICSMODE}
  FURLColor := gcBlue;
  FURLUnderline := True;
  {$ENDIF}
  SetFill(Fill);
  SetStroke(Stroke);
  SetFont(Font);
end;

{$IFDEF FMXLIB}
class function TAdvGraphics.GetColorAlpha(AColor: TAdvGraphicsColor): Byte;
begin
  Result := TAlphaColorRec(AColor).A;
end;
{$ENDIF}

class function TAdvGraphics.GetColorRed(AColor: TAdvGraphicsColor): Byte;
begin
  {$IFDEF FMXLIB}
  Result := TAlphaColorRec(AColor).R;
  {$ENDIF}
  {$IFDEF CMNLIB}
  AColor := ColorToRGB(AColor);
  Result := GetRValue(AColor);
  {$ENDIF}
end;

class function TAdvGraphics.GetColorGreen(AColor: TAdvGraphicsColor): Byte;
begin
  {$IFDEF FMXLIB}
  Result := TAlphaColorRec(AColor).G;
  {$ENDIF}
  {$IFDEF CMNLIB}
  AColor := ColorToRGB(AColor);
  Result := GetGValue(AColor);
  {$ENDIF}
end;

class function TAdvGraphics.GetColorBlue(AColor: TAdvGraphicsColor): Byte;
begin
  {$IFDEF FMXLIB}
  Result := TAlphaColorRec(AColor).B;
  {$ENDIF}
  {$IFDEF CMNLIB}
  AColor := ColorToRGB(AColor);
  Result := GetBValue(AColor);
  {$ENDIF}
end;

class function TAdvGraphics.TextToColor(AText: string): TAdvGraphicsColor;
var
  i: integer;
  s: string;
begin
  s := AText;

  s := LowerCase(s);
  if pos('cl',s) = 1 then
    Delete(s,1,2);

  if pos('cla',s) = 1 then
    Delete(s,1,3);

  if pos('gc',s) = 1 then
    Delete(s,1,2);

  Result := gcBlack;
  if Assigned(FColorLookup) then
  begin
    i := FColorLookup.IndexOf(LowerCase(s));
    if (i >= 0) and (i <= FColorLookup.Count - 1) then
      Result := TAdvGraphicsColorObject(FColorLookup.Objects[i]).Color;
  end;
end;

class function TAdvGraphics.HTMLToColor(AHTML: string): TAdvGraphicsColor;

function HexVal(s:string): Integer;
var
  i,j: Integer;
  i1, i2: Integer;
begin
  if Length(s) < 2 then
  begin
    Result := 0;
    Exit;
  end;

  {$IFDEF DELPHI_LLVM}
  i1 := 0;
  i2 := 1;
  {$ELSE}
  i1 := 1;
  i2 := 2;
  {$ENDIF}

  if s[i1] >= 'A' then
    i := ord(s[i1]) - ord('A') + 10
  else
    i := ord(s[i1]) - ord('0');

  if s[i2] >= 'A' then
    j := ord(s[i2]) - ord('A') + 10
  else
    j := ord(s[i2]) - ord('0');

  Result := i shl 4 + j;
end;

{$IFDEF CMNLIB}
var
  r,g,b: Integer;
begin
  r := Hexval(Copy(AHTML,2,2));
  g := Hexval(Copy(AHTML,4,2)) shl 8;
  b := Hexval(Copy(AHTML,6,2)) shl 16;
  Result := TColor(b + g + r);
{$ENDIF}

{$IFDEF FMXLIB}
const
  Alpha = TAdvGraphicsColor($FF000000);
var
  r,g,b: Integer;
begin
  r := Hexval(Copy(AHTML,2,2)) shl 16;
  g := Hexval(Copy(AHTML,4,2)) shl 8;
  b := Hexval(Copy(AHTML,6,2));
  Result := Alpha or TAdvGraphicsColor(b + g + r);
{$ENDIF}
end;

class function TAdvGraphics.ColorToHTML(AColor: TAdvGraphicsColor): string;
{$IFDEF CMNLIB}
type
  TAdvGraphicsColorRecord = record
    RedValue: Byte;
    GreenValue: Byte;
    BlueValue: Byte;
    SystemValue: Byte;
  end;
{$ENDIF}
const
  HTMLHexColor = '#RRGGBB';
  HexDigit: array[0..$F] of Char = '0123456789ABCDEF';
{$IFDEF FMXLIB}
var
  i: integer;
{$ENDIF}
begin
 {$IFNDEF FMXLIB}
  with TAdvGraphicsColorRecord(ColorToRGB(AColor)) do
  begin
    Result := HtmlHexColor;
    Result[2] := HexDigit[RedValue shr 4];
    Result[3] := HexDigit[RedValue and $F];
    Result[4] := HexDigit[GreenValue shr 4];
    Result[5] := HexDigit[GreenValue and $F];
    Result[6] := HexDigit[BlueValue shr 4];
    Result[7] := HexDigit[BlueValue and $F];
  end;
  {$ENDIF}
 {$IFDEF FMXLIB}
  with TAlphaColorRec(AColor) do
  begin
    Result := HTMLHexColor;
    {$IFDEF DELPHI_LLVM}
    i := 0;
    {$ELSE}
    i := 1;
    {$ENDIF}
    Result[1 + i] := HexDigit[R shr 4];
    Result[2 + i] := HexDigit[R and $F];
    Result[3 + i] := HexDigit[G shr 4];
    Result[4 + i] := HexDigit[G and $F];
    Result[5 + i] := HexDigit[B shr 4];
    Result[6 + i] := HexDigit[B and $F];
  end;
  {$ENDIF}
end;

function TAdvGraphics.DrawText(ARect: TRect; AText: String; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading;
  AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
  AMinWidth: Single = -1; AMinHeight: Single = -1{$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String;
var
  AControlID, AControlValue, AControlType: string;
begin
  AControlID := '';
  AControlValue := '';
  AControlType := '';
  Result := DrawText(ConvertToRectF(ARect), AText, AControlID, AControlValue, AControlType, AWordWrapping, AHorizontalAlign, AVerticalAlign, ATrimming, AAngle, AMinWidth, AMinHeight{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML, ATestAnchor, AX, AY{$ENDIF});
end;

function TAdvGraphics.DrawText(ARect: TRect; AText: String; var AControlID: string; var AControlValue: string; var AControlType: string; AWordWrapping: Boolean = False; AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading;
  AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
  AMinWidth: Single = -1; AMinHeight: Single = -1{$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String;
begin
  Result := DrawText(ConvertToRectF(ARect), AText, AControlID, AControlValue, AControlType, AWordWrapping, AHorizontalAlign, AVerticalAlign, ATrimming, AAngle, AMinWidth, AMinHeight{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML, ATestAnchor, AX, AY{$ENDIF});
end;

function TAdvGraphics.DrawText(ARect: TRectF; AText: String; AWordWrapping: Boolean = False;AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading;
  AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
  AMinWidth: Single = -1; AMinHeight: Single = -1{$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String;
var
  AControlID, AControlValue, AControlType: string;
begin
  AControlID := '';
  AControlValue := '';
  AControlType := '';
  Result := DrawText(ARect, AText, AControlID, AControlValue, AControlType, AWordWrapping, AHorizontalAlign, AVerticalAlign, ATrimming, AAngle, AMinWidth, AMinHeight{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML, ATestAnchor, AX, AY{$ENDIF});
end;

function TAdvGraphics.DrawText(ARect: TRectF; AText: String; var AControlID: string; var AControlValue: string; var AControlType: string; AWordWrapping: Boolean = False;AHorizontalAlign: TAdvGraphicsTextAlign = gtaLeading;
  AVerticalAlign: TAdvGraphicsTextAlign = gtaCenter; ATrimming: TAdvGraphicsTextTrimming = gttNone; AAngle: Single = 0;
  AMinWidth: Single = -1; AMinHeight: Single = -1{$IFNDEF LIMITEDGRAPHICSMODE};ASupportHTML: Boolean = True; ATestAnchor: Boolean = False; AX: Single = -1; AY: Single = - 1{$ENDIF}): String;
{$IFDEF CMNLIB}
var
  {$IFNDEF LIMITEDGRAPHICSMODE}
  a, s: String;
  fa: String;
  XSize, YSize: Single;
  hl, ml: Integer;
  hr, cr: TRectF;
  xs, ys: Single;
  lc: Integer;
  htmlr: TRectF;
  isanchor: boolean;
  st: TAdvGraphicsSaveState;
  {$ENDIF}
  r: TRect;
  {$IFDEF LCLLIB}
  {%H-}dstyle: TTextStyle;
  {$IFNDEF MSWINDOWS}
  crr: TRect;
  {$ENDIF}
  {$ENDIF}
  {$IFDEF VCLLIB}
  dstyle: TTextFormat;
  {$ENDIF}
  rcalc: TRectF;
  rh: Integer;
  c: TAdvGraphicsColor;
  bs: TBrushStyle;
  {$IFDEF GDIPLUSDRAWING}
  rt: TGPRectF;
  ft: TGPFont;
  sf: TGPStringFormat;
  b: TGPBrush;
  {$ENDIF}
begin
  inherited;

  c := FCanvas.Brush.Color;
  bs := FCanvas.Brush.Style;
  FCanvas.Brush.Style := bsClear;

  if (AMinHeight > -1) and (ARect.Height < AMinHeight) then
    ARect.Height := AMinHeight;

  if (AMinWidth > -1) and (ARect.Width < AMinWidth) then
    ARect.Width := AMinWidth;

  r := Rect(Round(ARect.Left), Round(ARect.Top), Round(ARect.Right), Round(ARect.Bottom));

  Result := '';

  {$IFNDEF LIMITEDGRAPHICSMODE}
  if ((AnsiPos('</', AText) > 0) or (AnsiPos('/>', AText)  > 0) or (AnsiPos('<BR>', UpperCase(AText)) > 0)) and ASupportHTML then
  begin
    hr := RectF(0, 0, 0, 0);
    XSize := 0;
    YSize := 0;
    hl := -1;
    ml := -1;
    fa := '';
    s := '';
    a := '';
    lc := 0;
    cr := RectF(0, 0, 0, 0);
    AControlID := '';
    AControlValue := '';
    AControlType := '';
    HTMLDrawEx(Self, AText, ARect,0, 0,-1,-1,0,False,True,False,False,False,False,AWordWrapping,False, '', 1.0,URLColor,
        gcNull,gcNull,gcNull,a,s,fa,XSize,YSize,hl,ml,hr,cr, AControlID, AControlValue, AControlType, lc, 0, FPictureContainer, 1, URLUnderline, FImageList,
        HighlightColor, HighlightTextColor, HighlightFontStyle);

    if (AWordWrapping and (lc <= 1)) or (not AWordWrapping) then
    begin
      xs := ARect.Left;
      ys := ARect.Top;

      case AHorizontalAlign of
        gtaCenter: xs := xs + (ARect.Width - XSize) / 2;
        gtaTrailing: xs := ARect.Left + ARect.Width - XSize;
      end;

      case AVerticalAlign of
        gtaCenter: ys := ys + (ARect.Height - YSize) / 2;
        gtaTrailing: ys := ys + ARect.Height - YSize;
      end;

      htmlr := RectF(xs, ys, xs + XSize, ys + YSize);
    end
    else
      htmlr := ARect;

    st := SaveState(True);
    ClipRect(ARect);
    isanchor := HTMLDrawEx(Self, AText, htmlr,Round(AX), Round(AY),-1,-1,0,ATestAnchor,False,False,False,False,False,AWordWrapping, False, '', 1.0,URLColor,
        gcNull,gcNull,gcNull,a,s,fa,XSize,YSize,hl,ml,hr,cr, AControlID, AControlValue, AControlType, lc, 0, FPictureContainer, 1, URLUnderline, FImageList,
        HighlightColor, HighlightTextColor, HighlightFontStyle);
    RestoreState(st, True);

    if isanchor then
      Result := a;
  end
  else if not ATestAnchor then
  {$ENDIF}
  begin
    {$IFDEF VCLLIB}
    dstyle := [];
    if AWordWrapping then
      dstyle := dstyle + [tfWordBreak]
    else
      dstyle := dstyle + [tfSingleLine];

    case AHorizontalAlign of
      gtaCenter: dstyle := dstyle + [tfCenter];
      gtaLeading: dstyle := dstyle + [tfLeft];
      gtaTrailing: dstyle := dstyle + [tfRight];
    end;

    case AVerticalAlign of
      gtaCenter: dstyle := dstyle + [tfVerticalCenter];
      gtaLeading: dstyle := dstyle + [tfTop];
      gtaTrailing: dstyle := dstyle + [tfBottom];
    end;

    case ATrimming of
      gttCharacter: dstyle := dstyle + [tfEndEllipsis];
      {$HINTS OFF}
      {$IF COMPILERVERSION > 22}
      gttWord: dstyle := dstyle + [tfWordEllipsis];
      {$IFEND}
      {$HINTS ON}
    end;
    {$ENDIF}

    {$IFDEF LCLLIB}
    dStyle.RightToLeft := False;
    dStyle.WordBreak := AWordWrapping;
    dStyle.SingleLine := not AWordWrapping;
    dStyle.Clipping := True;
    dStyle.EndEllipsis := False;
    dStyle.SystemFont := False;

    case AHorizontalAlign of
      gtaCenter: dstyle.Alignment := taCenter;
      gtaLeading: dstyle.Alignment := taLeftJustify;
      gtaTrailing: dstyle.Alignment := taRightJustify;
    end;

    case AVerticalAlign of
      gtaCenter: dstyle.Layout := tlCenter;
      gtaLeading: dstyle.Layout := tlTop;
      gtaTrailing: dstyle.Layout := tlBottom;
    end;

    case ATrimming of
      gttCharacter: dstyle.EndEllipsis := True;
    end;
    {$ENDIF}

    if AWordWrapping then
    begin
      case AVerticalAlign of
        gtaCenter:
        begin
          rcalc := CalculateText(AText, ARect, AWordWrapping);
          rh := Round(rcalc.Height);
          r.Top := r.Top +((r.Bottom - r.Top) - rh) div 2;
          r.Bottom := r.Top + rh;
        end;
        gtaTrailing:
        begin
          rcalc := CalculateText(AText, ARect, AWordWrapping);
          rh := Round(rcalc.Height);
          r.Top := r.Top + r.Bottom - rh;
          r.Bottom := r.Top + rh;
        end;
      end;
    end;

    if AAngle <> 0 then
      DrawRotatedText(FCanvas, r, AText, AAngle, AHorizontalAlign, AVerticalAlign)
    else
    begin
    {$IFDEF GDIPLUSDRAWING}
      b := CreateGDIPFontFill(Font);
      ft := CreateGDIPFont(Font);
      sf := CreateGPStringFormat(AHorizontalAlign, AVerticalAlign, AWordWrapping);
      try
        rt := MakeRect(ARect.Left, ARect.Top, ARect.Width, ARect.Height);
        FGDIPCanvas.DrawString(AText, Length(AText), ft, rt, sf, b);
      finally
        sf.Free;
        ft.Free;
        b.Free;
      end;
    {$ENDIF}
    {$IFNDEF GDIPLUSDRAWING}
    {$IFDEF VCLLIB}
      FCanvas.TextRect(r, AText, dstyle);
    {$ENDIF}
    {$IFDEF LCLLIB}
      {$IFNDEF MSWINDOWS}
      crr := Rect(0, 0, 0, 0);
      if not FCanvas.Clipping or (IntersectRect(crr, FCanvas.ClipRect, r) and FCanvas.Clipping) then
      {$ENDIF}
        FCanvas.TextRect(r, r.Left, r.Top, AText, dstyle);
    {$ENDIF}
    {$ENDIF}
    end;
  end;

  FCanvas.Brush.Color := c;
  FCanvas.Brush.Style := bs;
{$ENDIF}

{$IFDEF FMXLIB}
var
{$IFNDEF LIMITEDGRAPHICSMODE}
  a, s: String;
  fa: String;
  XSize, YSize: Single;
  hl, ml: Integer;
  hr, cr: TRectF;
  xs, ys: Single;
  lc: Integer;
  htmlr: TRectF;
  isanchor: boolean;
  st: TAdvGraphicsSaveState;
{$ENDIF}
  va, ha: TTextAlign;
  cx: TPointF;
  m, rm: TMatrix;
  ar: Single;
  oldc: TAdvGraphicsColor;
  {$IFDEF NATIVEIOSDRAWING}
  ft: UIFont;
  cr: CGRect;
  sz: Double;
  ww: Cardinal;
  {$ENDIF}
begin
  inherited;

  oldc := Canvas.Fill.Color;
  Canvas.Fill.Color := FFont.Color;

  if (AMinHeight > -1) and (ARect.Height < AMinHeight) then
    ARect.Height := AMinHeight;

  if (AMinWidth > -1) and (ARect.Width < AMinWidth) then
    ARect.Width := AMinWidth;

  if AAngle <> 0 then
  begin
    ar := DegToRad(AAngle);
    cx.X := ARect.Left + ARect.Width / 2;
    cx.Y := ARect.Top + ARect.Height / 2;
    m := FCanvas.Matrix;
    rm := TMatrix.CreateRotation(ar) * TMatrix.CreateTranslation(cx.X, cx.Y);
    FCanvas.MultiplyMatrix(rm);
    if ARect.Width < ARect.Height then
      ARect := RectF(-ARect.Height / 2, -ARect.Width / 2, ARect.Height / 2, ARect.Width / 2)
    else
      ARect := RectF(-ARect.Width / 2, -ARect.Height / 2, ARect.Width / 2, ARect.Height / 2);
  end;

  Result := '';
  va := TTextAlign(Integer(AVerticalAlign));
  ha := TTextAlign(Integer(AHorizontalAlign));

  {$IFNDEF LIMITEDGRAPHICSMODE}
  if ((AnsiPos('</', AText) > 0) or (AnsiPos('/>', AText)  > 0) or (AnsiPos('<BR>', UpperCase(AText)) > 0)) and ASupportHTML then
  begin
    hr := RectF(0, 0, 0, 0);
    XSize := 0;
    YSize := 0;
    hl := -1;
    ml := -1;
    fa := '';
    s := '';
    a := '';
    lc := 0;
    cr := RectF(0, 0, 0, 0);
    AControlID := '';
    AControlValue := '';
    AControlType := '';
    HTMLDrawEx(Self, AText, ARect,0, 0,-1,-1,0,False,True,False,False,False,False,AWordWrapping,False, '', 1.0,URLColor,
        gcNull,gcNull,gcNull,a,s,fa,XSize,YSize,hl,ml,hr, cr, AControlID, AControlValue, AControlType, lc, 0, FPictureContainer, 1, URLUnderline{$IFDEF CMNLIB}, FImageList{$ENDIF},
        HighlightColor, HighlightTextColor, HighlightFontStyle);

    if (AWordWrapping and (lc <= 1)) or (not AWordWrapping) then
    begin
      xs := ARect.Left;
      ys := ARect.Top;

      case AHorizontalAlign of
        gtaCenter: xs := xs + (ARect.Width - XSize) / 2;
        gtaTrailing: xs := ARect.Left + ARect.Width - XSize;
      end;

      case AVerticalAlign of
        gtaCenter: ys := ys + (ARect.Height - YSize) / 2;
        gtaTrailing: ys := ys + ARect.Height - YSize;
      end;

      htmlr := RectF(xs, ys, xs + XSize, ys + YSize);
    end
    else
      htmlr := ARect;

    st := SaveState(True);
    ClipRect(ARect);
    isanchor := HTMLDrawEx(Self, AText, htmlr,Round(AX), Round(AY),-1,-1,0,ATestAnchor,False,False,False,False,False,AWordWrapping,False, '', 1.0,URLColor,
        gcNull,gcNull,gcNull,a,s,fa,XSize,YSize,hl,ml,hr,cr, AControlID, AControlValue, AControlType, lc, 0, FPictureContainer, 1, URLUnderline{$IFDEF CMNLIB}, FImageList{$ENDIF},
        HighlightColor, HighlightTextColor, HighlightFontStyle);
    RestoreState(st, True);

    if isanchor then
      Result := a;
  end
  else if not ATestAnchor then
  {$ENDIF}
  begin
    {$IFDEF NATIVEIOSDRAWING}
    CGContextSaveGState(FContext);
    CGContextSetRGBFillColor(FContext, GetColorRed(Font.Color) / 255, GetColorGreen(Font.Color) / 255, GetColorBlue(Font.Color) / 255, GetColorAlpha(Font.Color) / 255);
    if TFontStyle.fsBold in Font.Style then
      ft := TUIFont.Wrap(TUIFont.OCClass.fontWithName(TAdvUtils.NSSTREx('Helvetica Bold'), Font.Size))
    else
      ft := TUIFont.Wrap(TUIFont.OCClass.fontWithName(TAdvUtils.NSSTREx('Helvetica'), Font.Size));

    sz := ft.pointSize;

    ww := NSLineBreakByClipping;
    if AWordWrapping then
      ww := NSLineBreakByWordWrapping;

    case va of
      TTextAlign.Center: cr := CGRectMake(ARect.Left, ARect.Top + (ARect.Height - sz) / 2, ARect.Width, sz);
      TTextAlign.Leading: cr := CGRectMake(ARect.Left, ARect.Top, ARect.Width, sz);
      TTextAlign.Trailing: cr := CGRectMake(ARect.Left, ARect.Bottom - sz, ARect.Width, sz);
    end;

    case ha of
      TTextAlign.Center: TNSString.Wrap((TAdvUtils.NSStrEx(AText) as ILocalObject).GetObjectID).drawInRect(cr, ft, ww, NSTextAlignmentCenter);
      TTextAlign.Leading: TNSString.Wrap((TAdvUtils.NSStrEx(AText) as ILocalObject).GetObjectID).drawInRect(cr, ft, ww, NSTextAlignmentLeft);
      TTextAlign.Trailing: TNSString.Wrap((TAdvUtils.NSStrEx(AText) as ILocalObject).GetObjectID).drawInRect(cr, ft, ww, NSTextAlignmentRight);
    end;

    CGContextRestoreGState(FContext);
    {$ELSE}
    if not Assigned(FTextLayout) then
      FTextLayout := TTextLayoutManager.DefaultTextLayout.Create(FCanvas);

    FTextLayout.BeginUpdate;
    try
      FTextLayout.TopLeft := PointF(Round(ARect.Left), Round(ARect.Top));
      FTextLayout.Text := AText;
      FTextLayout.MaxSize := PointF(Round(ARect.Width), Round(ARect.Height));
      FTextLayout.WordWrap := AWordWrapping;
      FTextLayout.Opacity := 1;
      FTextLayout.HorizontalAlign := ha;
      FTextLayout.VerticalAlign := va;
      FTextLayout.Font.Assign(FCanvas.Font);
      FTextLayout.Color := FCanvas.Fill.Color;
      if not AWordWrapping then
        FTextLayout.Trimming := TTextTrimming(Integer(ATrimming))
      else
        FTextLayout.Trimming := TTextTrimming.None;
    finally
      FTextLayout.EndUpdate;
    end;
    FTextLayout.RenderLayout(FCanvas);
    {$ENDIF}
  end;

  if AAngle <> 0 then
    FCanvas.SetMatrix(m);

  Canvas.Fill.Color := oldc;

  {$ENDIF}
end;

procedure TAdvGraphics.DrawEllipse(ALeft: Integer; ATop: Integer; ARight: Integer; ABottom: Integer; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawEllipse(RectF(ALeft, ATop, ARight, ABottom), AModifyRectMode);
end;

procedure TAdvGraphics.DrawEllipse(ALeft: Double; ATop: Double; ARight: Double; ABottom: Double; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
var
{$IFDEF FMXLIB}
  r: TRectF;
{$ENDIF}
{$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  r: TGPRectF;
  b: TGPBrush;
  p: TGPPen;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  r: TRect;
  ps: TPenStyle;
  bs: TBrushStyle;
  c: TAdvGraphicsColor;
  {$ENDIF}
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  r := RectF(ALeft, ATop, ARight, ABottom);
  r := ModifyRect(r, AModifyRectMode);
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    FCanvas.FillEllipse(r, FFill.Opacity);

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
    FCanvas.DrawEllipse(r, FStroke.Opacity);
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFDEF GDIPLUSDRAWING}
  r := MakeRect(ALeft, ATop, ARight - ALeft, ABottom - ATop);
  r.Width := r.Width - 1;
  r.Height := r.Height - 1;
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
  begin
    b := CreateGDIPFill(Fill, r);
    try
      FGDIPCanvas.FillEllipse(b, r);
    finally
      b.Free;
    end;
  end;

  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
  begin
    p := CreateGDIPStroke(Stroke);
    try
      FGDIPCanvas.DrawEllipse(p, r);
    finally
      p.Free;
    end;
  end;
  {$ENDIF}
  {$IFNDEF GDIPLUSDRAWING}
  r := Rect(Round(ALeft), Round(ATop), Round(ARight), Round(ABottom));

  ps := FCanvas.Pen.Style;
  FCanvas.Pen.Style := psClear;
  if (FFill.Color <> gcNull) and (FFill.Kind <> gfkNone) then
    FCanvas.Ellipse(r);
  FCanvas.Pen.Style := ps;

  c := FCanvas.Brush.Color;
  bs := FCanvas.Brush.Style;
  FCanvas.Brush.Style := bsClear;
  if (FStroke.Color <> gcNull) and (FStroke.Kind <> gskNone) then
    FCanvas.Ellipse(r);
  FCanvas.Brush.Style := bs;
  FCanvas.Brush.Color := c;
  {$ENDIF}
  {$ENDIF}
end;

class procedure TAdvGraphics.ConvertBitmapToGrayScale(ABitmap: TAdvBitmap);
type
  TAdvGraphicsColorToGrayscale = (ctgLightness, ctgAverage, ctgLuminosity);

  function MinColor(const A, B, C: Integer): Integer;
  begin
    Result := Min(A, Min(B, C));
  end;

  function MaxColor(const A, B, C: Integer): Integer;
  begin
    Result := Max(A, Max(B, C));
  end;

  function ColorToGray(AColor: TAdvGraphicsColor; AMode: TAdvGraphicsColorToGrayscale = ctgLuminosity): TAdvGraphicsColor;
  var
    R, G, B, X: Byte;
    {$IFNDEF CMNLIB}
    A: Byte;
    {$ENDIF}
  begin
    {$IFDEF FMXLIB}
    R := TAlphaColorRec(AColor).R;
    G := TAlphaColorRec(AColor).G;
    B := TAlphaColorRec(AColor).B;
    A := TAlphaColorRec(AColor).A;
    {$ENDIF}
    {$IFDEF CMNLIB}
    R := AColor and $FF;
    G := (AColor and $FF00) shr 8;
    B := (AColor and $FF0000) shr 16;
    {$ENDIF}
    X := 0;
    case AMode of
      ctgLightness: X := (MaxColor(R, G, B) + MinColor(R, G, B)) div 2;
      ctgAverage: X := (R + G + B) div 3;
      ctgLuminosity: X := Round(0.21 *R + 0.71*G + 0.07*B);
    end;
    {$IFDEF FMXLIB}
    Result := MakeGraphicsColor(X, X, X, A);
    {$ENDIF}
    {$IFDEF CMNLIB}
    Result := TAdvGraphicsColor(RGB(X, X, X));
    {$ENDIF}
  end;

var
  I, J: Integer;
  {$IFDEF FMXLIB}
  m: TBitmapData;
  {$ENDIF}
begin
  if Assigned(ABitmap) and not IsBitmapEmpty(ABitmap) then
  begin
    {$IFDEF FMXLIB}
    if ABitmap.Map(TMapAccess.ReadWrite, m) then
    begin
    {$ENDIF}
    {$IFDEF CMNLIB}
    begin
    {$ENDIF}
      for I := 0 to ABitmap.Width - 1 do
      begin
        for J := 0 to ABitmap.Height - 1 do
        begin
          {$IFDEF CMNLIB}
          ABitmap.Bitmap.Canvas.Pixels[I, J] := ColorToGray(ABitmap.Bitmap.Canvas.Pixels[I, J]);
          {$ENDIF}
          {$IFDEF FMXLIB}
          m.SetPixel(I, J, ColorToGray(m.GetPixel(I, J)));
          {$ENDIF}
        end;
      end;
      {$IFDEF FMXLIB}
      ABitmap.Unmap(m);
      {$ENDIF}
    end;
  end;
end;

class procedure TAdvGraphics.DrawSample(ACanvas: TCanvas; ARect: TRectF);
var
  g: TAdvGraphics;
begin
  g := TAdvGraphics.Create(ACanvas);
  try
    g.Font.Name := 'Courier New';
    g.Font.Size := 20;
    g.Font.Color := gcWhite;
    g.Fill.Kind := gfkGradient;
    g.Fill.Color := gcDarkorange;
    g.Fill.ColorTo := gcSteelblue;
    g.Stroke.Color := gcDarkblue;
    g.DrawRectangle(ARect);
    g.DrawText(ARect, 'Sample', False, gtaCenter);
  finally
    g.Free;
  end;
end;

class function TAdvGraphics.PointInPolygon(APoint: TPoint; APolygon: TAdvGraphicsPathPolygon): Boolean;
begin
  Result := PointInPolygon(ConvertToPointF(APoint), APolygon);
end;

class function TAdvGraphics.PointInPolygon(APoint: TPointF; APolygon: TAdvGraphicsPathPolygon): Boolean;
var
  minX, maxX, minY, maxY: Double;
  I, J: Integer;
  q: TPointF;
  pt, ptn: TPointF;
  inside, chk: Boolean;
  calc: Double;
  chkc: Boolean;
begin
  minX := APolygon[0].X;
  maxX := APolygon[0].X;
  minY := APolygon[0].Y;
  maxY := APolygon[0].Y;

  for I := 1 to Length(APolygon) - 1 do
  begin
    q := APolygon[I];
    minX := Min(q.X, minX);
    maxX := Max(q.X, maxX);
    minY := Min(q.Y, minY);
    maxY := Max(q.Y, maxY);
  end;

  if (APoint.X < minX) or (APoint.X > maxX) or (APoint.Y < minY) or (APoint.Y > maxY) then
  begin
    Result := False;
    Exit;
  end;

  inside := False;
  J := Length(APolygon) - 1;
  for I := 0 to Length(APolygon) - 1 do
  begin
    pt := APolygon[I];
    ptn := APolygon[J];
    chk := (pt.Y > APoint.Y) <> (ptn.Y > APoint.Y);
    if (ptn.Y - pt.Y) <> 0 then
    begin
      calc := (ptn.X - pt.X) * (APoint.Y - pt.Y) / (ptn.Y - pt.Y) + pt.X;
      chkc := APoint.X < calc;
      if chk and chkc then
        inside := not inside;
    end;

    j := I;
  end;
  Result := inside;
end;

class function TAdvGraphics.PointInRect(APoint: TPoint; ARect: TRect): Boolean;
begin
  Result := PointInRect(ConvertToPointF(APoint), ConvertToRectF(ARect));
end;

class function TAdvGraphics.PointInRect(APoint: TPointF; ARect: TRectF): Boolean;
begin
  Result := PtInRectEx(ARect, APoint);
end;

class function TAdvGraphics.PointInPath(APoint: TPoint; APath: TAdvGraphicsPath): Boolean;
begin
  Result := PointInPath(ConvertToPointF(APoint), APath);
end;

class function TAdvGraphics.PointInPath(APoint: TPointF; APath: TAdvGraphicsPath): Boolean;
var
  p: TAdvGraphicsPathPolygon;
begin
  SetLength(p, 0);
  APath.FlattenToPolygon(p);
  Result := PointInPolygon(APoint, p);
end;

function TAdvGraphics.CalculateTextSizeInt(AText: String): TSize;
begin
  Result := ConvertToSize(CalculateTextSize(AText));
end;

function TAdvGraphics.CalculateTextSize(AText: String): TSizeF;
begin
  Result := CalculateTextSize(AText, RectF(0, 0, 10000, 10000));
end;

function TAdvGraphics.CalculateTextHeightInt(AText: String): Integer;
begin
  Result := Round(CalculateTextHeight(AText));
end;

function TAdvGraphics.CalculateTextHeight(AText: String): Single;
begin
  Result := CalculateTextHeight(AText, RectF(0, 0, 10000, 10000));
end;

function TAdvGraphics.CalculateTextWidthInt(AText: String): Integer;
begin
  Result := Round(CalculateTextWidth(AText));
end;

function TAdvGraphics.CalculateTextWidth(AText: String): Single;
begin
  Result := CalculateTextWidth(AText, RectF(0, 0, 10000, 10000));
end;

function TAdvGraphics.CalculateTextSize(AText: String; ARect: TRect; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): TSize;
begin
  Result := ConvertToSize(CalculateTextSize(AText, ConvertToRectF(ARect), AWordWrapping{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML{$ENDIF}));
end;

function TAdvGraphics.CalculateTextSize(AText: String; ARect: TRectF; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): TSizeF;
var
  r: TRectF;
begin
  r := CalculateText(AText, ARect, AWordWrapping{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML{$ENDIF});
  Result.Width := r.Width;
  Result.Height := r.Height;
end;

function TAdvGraphics.CalculateTextHeight(AText: String; ARect: TRect; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): Integer;
begin
  Result := Round(CalculateTextHeight(AText, ConvertToRectF(ARect), AWordWrapping{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML{$ENDIF}));
end;

function TAdvGraphics.CalculateTextHeight(AText: String; ARect: TRectF; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): Single;
begin
  Result := CalculateText(AText, ARect, AWordWrapping{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML{$ENDIF}).Height;
end;

function TAdvGraphics.CalculateTextWidth(AText: String; ARect: TRect; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): Integer;
begin
  Result := Round(CalculateTextWidth(AText, ConvertToRectF(ARect), AWordWrapping{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML{$ENDIF}));
end;

function TAdvGraphics.CalculateTextWidth(AText: String; ARect: TRectF; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): Single;
begin
  Result := CalculateText(AText, ARect, AWordWrapping{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML{$ENDIF}).Width;
end;

function TAdvGraphics.CalculateTextInt(AText: String): TRect;
begin
  Result := ConvertToRect(CalculateText(AText));
end;

function TAdvGraphics.CalculateText(AText: String): TRectF;
begin
  Result := CalculateText(AText, RectF(0, 0, 10000, 10000));
end;

{$IFDEF FMXWINDOWS}
function TAdvGraphics.CalculateTextWin(AText: string; ARect: TRectF; AWordWrapping: Boolean): TRectF;
var
  TextRange: TDWriteTextRange;
  TextFormat: IDWriteTextFormat;
  LocaleName: string;
  TrimOptions: TDwriteTrimming;
  TrimmingSign: IDWriteInlineObject;
  FLayout: IDWriteTextLayout;
  FMetrics: TDWriteTextMetrics;
  FOverhangMetrics: TDwriteOverhangMetrics;
  PrevFPUState: TArithmeticExceptionMask;

  procedure SaveClearFPUState;
  begin
    PrevFPUState:= GetExceptionMask;
    SetExceptionMask(exAllArithmeticExceptions);
  end;

  procedure RestoreFPUState;
  begin
    SetExceptionMask(PrevFPUState);
  end;

  function D2FontWeight(const Style: TFontStyles): TDWriteFontWeight; inline;
  begin
    Result := DWRITE_FONT_WEIGHT_REGULAR;
    if TFontStyle.fsBold in Style then
      Result := DWRITE_FONT_WEIGHT_BOLD;
  end;

  function D2FontStyle(const Style: TFontStyles): TDWriteFontStyle; inline;
  begin
    Result := 0;
    if TFontStyle.fsItalic in Style then
      Result := Result + DWRITE_FONT_STYLE_OBLIQUE;
  end;

  procedure UpdateDirect3DLevel;
  var
    DXLib: THandle;
  begin
    if FDirect3DLevel = TDirect3DLevel.lUndetermined then
    begin
      {$HINTS OFF}
      if {$IF COMPILERVERSION > 27}GlobalUseDX{$ELSE}GlobalUseDX10{$IFEND} then
      {$HINTS ON}
      begin
        FDirect3DLevel := TDirect3DLevel.lUndetermined;

        // Direct3D 10.1
        DXLib := LoadLibrary(D3D10_1_dll);
        if DXLib <> 0 then
        try
          if GetProcAddress(DXLib, 'D3D10CreateDevice1') <> nil then
            FDirect3DLevel := TDirect3DLevel.lDirect3D10_1;
        finally
          FreeLibrary(DXLib);
        end;

        if FDirect3DLevel = TDirect3DLevel.lUndetermined then
        begin // Direct3D 10.0
          DXLib := LoadLibrary(D3D10dll);
          if DXLib <> 0 then
          try
            if GetProcAddress(DXLib, 'D3D10CreateDevice') <> nil then
              FDirect3DLevel := TDirect3DLevel.lDirect3D10;
          finally
            FreeLibrary(DXLib);
          end;
        end;

        if FDirect3DLevel = TDirect3DLevel.lUndetermined then
          FDirect3DLevel := TDirect3DLevel.lUnsupported;
      end
      else
        FDirect3DLevel := TDirect3DLevel.lUnsupported;
    end;
  end;

  procedure CreateDirect3DDevice;

  function CreateDevice(const DriverType: D3D10_DRIVER_TYPE): HResult;
  var
    Flags: Cardinal;
  begin
    Result := S_OK;
    Flags := D3D10_CREATE_DEVICE_BGRA_SUPPORT;

    if FDirect3DLevel = TDirect3DLevel.lDirect3D10_1 then
    begin
      // Direct3D 10.1 with full hardware support
      Result := D3D10CreateDevice1(nil, DriverType, 0, Flags, D3D10_FEATURE_LEVEL_10_1,
        D3D10_1_SDK_VERSION, ID3D10Device1(FSharedDevice));

      if Succeeded(Result) then
        FDirect3DSupport := TDirect3DSupport.sDirect3D10_1;

      if Failed(Result) then
      begin
        // Direct3D 10.1 with hardware support of 10.0
        Result := D3D10CreateDevice1(nil, DriverType, 0, Flags, D3D10_FEATURE_LEVEL_10_0,
          D3D10_1_SDK_VERSION, ID3D10Device1(FSharedDevice));

        if Succeeded(Result) then
          FDirect3DSupport := TDirect3DSupport.sDirect3D10;
      end;
    end;

    if (FDirect3DLevel = TDirect3DLevel.lDirect3D10) or Failed(Result) then
    begin
      // Legacy Direct3D 10.0 (on unpatched version of Vista)
      Result := D3D10CreateDevice(nil, DriverType, 0, Flags, D3D10_SDK_VERSION, FSharedDevice);

      if Succeeded(Result) then
      begin
        FDirect3DLevel := TDirect3DLevel.lDirect3D10;
        FDirect3DSupport := TDirect3DSupport.sDirect3D10Legacy;
      end;
    end;
  end;

var
  Res: HResult;
begin
  if FDirect3DLevel < TDirect3DLevel.lDirect3D10 then
    raise Exception.CreateFmt('Cannot determine Direct3D support level.', [TAdvGraphics]);

  SaveClearFPUState;
  try
    {$HINTS OFF}
    if {$IF COMPILERVERSION > 27}GlobalUseDXSoftware{$ELSE}GlobalUseDX10Software{$IFEND} then
    {$HINTS ON}
    begin
      Res := CreateDevice(D3D10_DRIVER_TYPE_WARP);
      if Failed(Res) then
      begin
        // WARP device might not be supported on pre-DX10.1 system, which may still support DX10 in hardware.
        Res := CreateDevice(D3D10_DRIVER_TYPE_HARDWARE);
        if Succeeded(Res) then
          FDirect3DHardware := True;
      end
      else
        FDirect3DHardware := False;
    end
    else
    begin
      Res := CreateDevice(D3D10_DRIVER_TYPE_HARDWARE);
      if Failed(Res) then
      begin
        Res := CreateDevice(D3D10_DRIVER_TYPE_WARP);
        if Succeeded(Res) then
          FDirect3DHardware := False;
      end
      else
        FDirect3DHardware := True;
    end;

    if Failed(Res) then
      raise ECannotCreateD3DDevice.CreateFmt(SCannotCreateD3DDevice, [TAdvGraphics]);
  finally
    RestoreFPUState;
  end;
end;

procedure AcquireDXGIFactory;
var
  DXGIDevice: IDXGIDevice;
  DXGIAdapter: IDXGIAdapter;
begin
  if Succeeded(FSharedDevice.QueryInterface(IDXGIDevice, DXGIDevice)) and (DXGIDevice <> nil) and
    Succeeded(DXGIDevice.GetParent(IDXGIAdapter, DXGIAdapter)) and (DXGIAdapter <> nil) then
      DXGIAdapter.GetParent(IDXGIFactory, FSharedDXGIFactory);
end;

procedure CreateDirect2DFactory;
var
  FactoryOptions: PD2D1FactoryOptions;
  Res: HResult;
begin
  FactoryOptions := nil;
  Res := D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, ID2D1Factory, FactoryOptions, FSharedFactory);
  if Failed(Res) or (FSharedFactory = nil) then
    raise Exception.CreateFmt('Cannot create Direct2D Factory object for ''%s''.', [TAdvGraphics]);

  if Failed(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, IDWriteFactory, IUnknown(FSharedDWriteFactory))) then
    raise Exception.CreateFmt('Cannot create DirectWrite Factory object for ''%s''.', [TAdvGraphics]);
end;


  procedure CreateSharedResources;
  begin
    UpdateDirect3DLevel;
    if FSharedDevice = nil then
    begin
      CreateDirect3DDevice;
      AcquireDXGIFactory;
    end;
    if FSharedFactory = nil then
      CreateDirect2DFactory;
  end;

  function SharedDWriteFactory: IDWriteFactory;
  begin
    if FSharedDWriteFactory = nil then
      CreateSharedResources;
    Result := FSharedDWriteFactory;
  end;

var
  r: TRectF;
  dwVersion:Dword;
  dwWindowsMajorVersion: Dword;
begin
  dwVersion := GetVersion;
  dwWindowsMajorVersion :=  DWORD(LOBYTE(LOWORD(dwVersion)));
  if (dwWindowsMajorVersion = 5) then
  begin
    r := ARect;
    FCanvas.MeasureText(r, AText, AWordWrapping, [], TTextAlign.Leading, TTextAlign.Leading);
    Result := r;
  end
  else
  begin
    Result := RectF(0, 0, 0, 0);
    if not Assigned(FCanvas) then
      Exit;

    FLayout := nil;
    if Succeeded(SharedDWriteFactory.CreateTextFormat(PChar(FCanvas.Font.Name), nil, D2FontWeight(FCanvas.Font.Style),
      D2FontStyle(FCanvas.Font.Style), DWRITE_FONT_STRETCH_NORMAL, FCanvas.Font.Size, PChar(LocaleName), TextFormat)) then
    try
      TextFormat.SetReadingDirection(DWRITE_READING_DIRECTION_LEFT_TO_RIGHT);

      if not AWordWrapping then
        TextFormat.SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP)
      else
        TextFormat.SetWordWrapping(DWRITE_WORD_WRAPPING_WRAP);

      FillChar(TrimOptions, SizeOf(TDwriteTrimming), 0);
      TrimOptions.granularity := DWRITE_TRIMMING_GRANULARITY_NONE;

      TrimmingSign := nil;
      TextFormat.SetTrimming(TrimOptions, TrimmingSign);
      TrimmingSign := nil;

      if Succeeded(SharedDWriteFactory.CreateTextLayout(PChar(AText), AText.Length, TextFormat, ARect.Width,
        ARect.Height, FLayout)) then
      begin
        TextRange.StartPosition := 0;
        TextRange.Length := AText.Length;
        FLayout.SetStrikethrough(TFontStyle.fsStrikeOut in FCanvas.Font.Style, TextRange);
        FLayout.SetUnderline(TFontStyle.fsUnderline in FCanvas.Font.Style, TextRange);
        FLayout.GetMetrics(FMetrics);
        FLayout.GetOverhangMetrics(FOverhangMetrics);

        Result := TRectF.Create(FMetrics.left, FMetrics.top,
          FMetrics.left + {Max(}FMetrics.widthIncludingTrailingWhitespace{, FOverhangMetrics.Right + AMaxRect.Width)},
          FMetrics.top + Min(FMetrics.height, FMetrics.layoutHeight));
        Result.Offset(ARect.TopLeft);
        if FMetrics.top < 0 then
          Result.Offset(0, Abs(FMetrics.top));
      end;
    finally
      TextFormat := nil;
    end;
  end;
end;
{$ENDIF}

function TAdvGraphics.CalculateText(AText: String;
  ARect: TRect; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): TRect;
begin
  Result := ConvertToRect(CalculateText(AText, ConvertToRectF(ARect), AWordWrapping{$IFNDEF LIMITEDGRAPHICSMODE}, ASupportHTML{$ENDIF}));
end;

function TAdvGraphics.CalculateText(AText: String;
  ARect: TRectF; AWordWrapping: Boolean = False{$IFNDEF LIMITEDGRAPHICSMODE}; ASupportHTML: Boolean = True{$ENDIF}): TRectF;
{$IFDEF CMNLIB}
var
  {$IFDEF VCLLIB}
  dstyle: TTextFormat;
  {$ENDIF}
  {$IFDEF LCLLIB}
  dstyle: Word;
  {$ENDIF}
  r: TRect;
  {$IFNDEF LIMITEDGRAPHICSMODE}
  a, s: String;
  fa: String;
  lc: Integer;
  XSize, YSize: Single;
  hl, ml: Integer;
  hr, cr: TRectF;
  AControlID, AControlType, AControlValue: string;
  {$ENDIF}
  {$IFDEF GDIPLUSDRAWING}
  rt: TGPRectF;
  b: TGPBrush;
  bb: TGPRectF;
  ft: TGPFont;
  sf: TGPStringFormat;
  {$ENDIF}
begin
  Result := ARect;
  if Round(Result.Width) <= 0 then
  begin
    Result.Height := 0;
    Exit;
  end;

  {$IFDEF VCLLIB}
  dstyle := [tfCalcRect];
  if AWordWrapping then
    dstyle := dstyle + [tfWordBreak]
  else
    dstyle := dstyle + [tfSingleLine];
  {$ENDIF}
  {$IFDEF LCLLIB}
  dstyle := DT_CALCRECT;
  if AWordWrapping then
    dstyle := dstyle or DT_WORDBREAK
  else
    dstyle := dstyle or DT_SINGLELINE;
  {$ENDIF}

  r := Rect(Round(ARect.Left), Round(ARect.Top), Round(ARect.Right), Round(ARect.Bottom));

  if AText <> '' then
  begin
    {$IFNDEF LIMITEDGRAPHICSMODE}
    if ASupportHTML and ((AnsiPos('</', AText) > 0) or (AnsiPos('/>', AText)  > 0) or (AnsiPos('<BR>', UpperCase(AText)) > 0)) then
    begin
      hr := RectF(0, 0, 0, 0);
      XSize := 0;
      YSize := 0;
      hl := -1;
      ml := -1;
      fa := '';
      s := '';
      a := '';
      lc := 0;
      cr := RectF(0, 0, 0, 0);
      AControlID := '';
      AControlValue := '';
      AControlType := '';
      HTMLDrawEx(Self, AText, ARect, 0, 0,-1,-1,0,False,True,False,False,False,False,AWordWrapping,False, '', 1.0,URLColor,
        gcNull,gcNull,gcNull,a,s,fa,XSize,YSize,hl,ml,hr,cr, AControlID, AControlValue, AControlType, lc, 0, FPictureContainer, 1, URLUnderline, FImageList,
        HighlightColor, HighlightTextColor, HighlightFontStyle);

      Result := RectF(r.Left, r.Top, r.Left + XSize, r.Top + YSize);
    end
    else
    {$ENDIF}
    begin
      {$IFDEF GDIPLUSDRAWING}
      b := CreateGDIPFontFill(Font);
      ft := CreateGDIPFont(Font);
      sf := CreateGPStringFormat(gtaLeading, gtaLeading, AWordWrapping);
      try
        rt := MakeRect(ARect.Left, ARect.Top, ARect.Width, ARect.Height);
        FGDIPCanvas.MeasureString(AText, Length(AText), ft, rt, sf, bb);
        Result := RectF(bb.X, bb.Y, bb.X + bb.Width, bb.Y + bb.Height);
      finally
        sf.Free;
        ft.Free;
        b.Free;
      end;
      {$ENDIF}
      {$IFNDEF GDIPLUSDRAWING}
      {$IFDEF VCLLIB}
      FCanvas.TextRect(r, AText, dstyle);
      {$ENDIF}
      {$IFDEF LCLLIB}
      LCLIntF.DrawText(FCanvas.Handle, PChar(AText), Length(AText), r, dstyle);
      {$ENDIF}
      Result := RectF(r.Left, r.Top, r.Right, r.Bottom);
      {$ENDIF}
    end;
  end
  else
  begin
    Result.Height := 0;
    Result.Width := 0;
  end;
{$ENDIF}

{$IFDEF FMXLIB}
{$IFNDEF LIMITEDGRAPHICSMODE}
var
  a, s: String;
  fa: String;
  XSize, YSize: Single;
  hl, ml: Integer;
  hr, cr: TRectF;
  lc: Integer;
  AControlID, AControlType, AControlValue: string;
{$ENDIF}
begin
  Result := ARect;
  if AText <> '' then
  begin
    {$IFNDEF LIMITEDGRAPHICSMODE}
    if ASupportHTML and ((AnsiPos('</', AText) > 0) or (AnsiPos('/>', AText)  > 0) or (AnsiPos('<BR>', UpperCase(AText)) > 0)) then
    begin
      cr := RectF(0, 0, 0, 0);
      AControlID := '';
      AControlValue := '';
      AControlType := '';
      HTMLDrawEx(Self, AText, ARect, 0, 0,-1,-1,0,False,True,False,False,False,False,AWordWrapping,False, '', 1.0,URLColor,
        gcNull,gcNull,gcNull,a,s,fa,XSize,YSize,hl,ml,hr,cr, AControlID, AControlValue, AControlType, lc, 0, FPictureContainer, 1, URLUnderline{$IFDEF CMNLIB}, FImageList{$ENDIF},
        HighlightColor, HighlightTextColor, HighlightFontStyle);

      Result.Width := XSize;
      Result.Height := YSize;
    end
    else
    {$ENDIF}
    begin
    {$IFDEF MSWINDOWS}
      Result := CalculateTextWin(AText, Result, AWordWrapping)
    {$ELSE}
      FCanvas.MeasureText(Result, AText, AWordWrapping, [], TTextAlign.Leading, TTextAlign.Leading)
    {$ENDIF}
    end;
  end
  else
  begin
    Result.Height := 0;
    Result.Width := 0;
  end;
  {$ENDIF}
end;

procedure TAdvGraphics.DrawEllipse(ARect: TRect; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawEllipse(ConvertToRectF(ARect), AModifyRectMode);
end;

procedure TAdvGraphics.DrawEllipse(ARect: TRectF; AModifyRectMode: TAdvGraphicsModifyRectMode = gcrmShrinkAll);
begin
  DrawEllipse(ARect.Left, ARect.Top, ARect.Right, ARect.Bottom, AModifyRectMode);
end;

function ModifyRect(const ARect: TRectF; const ARectMode: TAdvGraphicsModifyRectMode): TRectF;
begin
  Result := ARect;
  {$IFDEF FMXLIB}
  case ARectMode of
    gcrmExpandAll: Result := RectF(int(Result.Left) - 0.5, int(Result.Top) - 0.5, int(Result.Right) + 0.5, int(Result.Bottom) + 0.5);
    gcrmShrinkAll: Result := RectF(int(Result.Left) + 0.5, int(Result.Top) + 0.5, int(Result.Right) - 0.5, int(Result.Bottom) - 0.5);
    gcrmShiftRightAndExpandHeight: Result := RectF(int(Result.Left) + 0.5, int(Result.Top) - 0.5, int(Result.Right) + 0.5, int(Result.Bottom) + 0.5);
    gcrmShiftRightDown: Result := RectF(int(Result.Left) + 0.5, int(Result.Top) + 0.5, int(Result.Right) + 0.5, int(Result.Bottom) + 0.5);
    gcrmShiftRightAndShrinkHeight: Result := RectF(int(Result.Left) + 0.5, int(Result.Top) + 0.5, int(Result.Right) + 0.5, int(Result.Bottom) - 0.5);
    gcrmShiftDownAndExpandWidth: Result := RectF(int(Result.Left) - 0.5, int(Result.Top) + 0.5, int(Result.Right) + 0.5, int(Result.Bottom) + 0.5);
    gcrmShiftUpAndExpandWidth: Result := RectF(int(Result.Left) - 0.5, int(Result.Top) - 0.5, int(Result.Right) + 0.5, int(Result.Bottom) - 0.5);
    gcrmShiftRightUp: Result := RectF(Int(Result.Left) + 0.5, Int(Result.Top) - 0.5, Int(Result.Right) + 0.5, Int(Result.Bottom) - 0.5);
    gcrmShiftLeftUp: Result := RectF(Int(Result.Left) - 0.5, Int(Result.Top) - 0.5, Int(Result.Right) - 0.5, Int(Result.Bottom) - 0.5);
    gcrmShiftLeftDown: Result := RectF(Int(Result.Left) - 0.5, Int(Result.Top) + 0.5, Int(Result.Right) - 0.5, Int(Result.Bottom) + 0.5);
    gcrmShiftLeftAndExpandHeight: Result := RectF(int(Result.Left) - 0.5, int(Result.Top) - 0.5, int(Result.Right) - 0.5, int(Result.Bottom) + 0.5);
  end;
  {$ENDIF}
end;

function ModifyPoint(const APoint: TPointF; const APointMode: TAdvGraphicsModifyPointMode): TPointF;
begin
  Result := APoint;
  {$IFDEF FMXLIB}
  case APointMode of
    gcpmRightDown: Result := PointF(Int(Result.X) + 0.5, Int(Result.Y) + 0.5);
    gcpmLeftUp: Result := PointF(Int(Result.X) - 0.5, Int(Result.Y) - 0.5);
    gcpmRightUp: Result := PointF(Int(Result.X) + 0.5, Int(Result.Y) - 0.5);
    gcpmLeftDown: Result := PointF(Int(Result.X) - 0.5, Int(Result.Y) + 0.5);
  end;
  {$ENDIF}
end;

{ TAdvGraphicsFont }

constructor TAdvGraphicsFont.Create;
begin
  inherited Create;
  {$IFDEF FMXLIB}
  FColor := gcBlack;
  {$ENDIF}
  {$IFDEF CMNLIB}
  OnChange := DoChanged;
  {$ENDIF}
end;

{$IFDEF CMNLIB}
{$IFDEF LCLLIB}
procedure TAdvGraphicsFont.Changed;
begin
  inherited;
  DoChanged(Self);
end;
{$ENDIF}

procedure TAdvGraphicsFont.DoChanged(Sender: TObject);
begin
  if Assigned(OnChanged) then
    OnChanged(Self);
end;
{$ENDIF}

procedure TAdvGraphicsFont.Assign(Source: TPersistent);
begin
  inherited Assign(Source);
  {$IFDEF FMXLIB}
  if Source is TAdvGraphicsFont then
    FColor := (Source as TAdvGraphicsFont).Color;
  {$ENDIF}
  {$IFDEF CMNLIB}
  DoChanged(Self);
  {$ENDIF}
  if Assigned(OnChanged) then
    OnChanged(Self);
end;

{$IFDEF FMXLIB}
procedure TAdvGraphicsFont.SetName(const Value: string);
begin
  Family := Value;
end;

function TAdvGraphicsFont.GetName: string;
begin
  Result := Family;
end;

procedure TAdvGraphicsFont.SetColor(const Value: TAdvGraphicsColor);
begin
  if FColor <> Value then
  begin
    FColor := Value;
    {$IFDEF CMNLIB}
    if FColor = clNone then
      FColor := gcNull
    else if FColor = clDefault then
      FColor := clBtnFace;
    {$ENDIF}
    if Assigned(OnChanged) then
      OnChanged(Self);
  end;
end;

{$ENDIF}

{ TAdvGraphicsSaveState }

constructor TAdvGraphicsSaveState.Create;
begin
  inherited;
  FFill := TAdvGraphicsFill.Create;
  FStroke := TAdvGraphicsStroke.Create;
  FFont := TAdvGraphicsFont.Create;
end;

destructor TAdvGraphicsSaveState.Destroy;
begin
  FFill.Free;
  FStroke.Free;
  FFont.Free;
  inherited;
end;

procedure TAdvGraphicsSaveState.SetFill(const Value: TAdvGraphicsFill);
begin
  FFill.Assign(Value);
end;

procedure TAdvGraphicsSaveState.SetFont(const Value: TAdvGraphicsFont);
begin
  FFont.Assign(Value);
end;

procedure TAdvGraphicsSaveState.SetStroke(const Value: TAdvGraphicsStroke);
begin
  FStroke.Assign(Value);
end;

{ TAdvCustomGraphicsFill }

procedure TAdvCustomGraphicsFill.Assign(Source: TPersistent);
begin
  if Source is TAdvCustomGraphicsFill then
  begin
    FColor := (Source as TAdvCustomGraphicsFill).Color;
    FColorTo := (Source as TAdvCustomGraphicsFill).ColorTo;
    FColorMirror := (Source as TAdvCustomGraphicsFill).ColorMirror;
    FColorMirrorTo := (Source as TAdvCustomGraphicsFill).ColorMirrorTo;
    FKind := (Source as TAdvCustomGraphicsFill).Kind;
    FOrientation := (Source as TAdvCustomGraphicsFill).Orientation;
    {$IFDEF FMXLIB}
    FOpacity := (Source as TAdvCustomGraphicsFill).Opacity;
    {$ENDIF}
  end
  else if Source is TAdvCustomGraphicsStroke then
  begin
    FColor := (Source as TAdvCustomGraphicsStroke).Color;
    FColorTo := gcNull;
    FColorMirror := gcNull;
    FColorMirrorTo := gcNull;
    FKind := gfkSolid;
    FOrientation := gfoVertical;
    {$IFDEF FMXLIB}
    FOpacity := 1;
    {$ENDIF}
  end;
  Changed;
end;

procedure TAdvCustomGraphicsFill.Changed;
begin
  if Assigned(OnChanged) then
    OnChanged(Self);
end;

constructor TAdvCustomGraphicsFill.Create(const AKind: TAdvGraphicsFillKind = gfkSolid; const AColor: TAdvGraphicsColor = gcWhite);
begin
  FKind := AKind;
  {$IFDEF FMXLIB}
  FOpacity := 1;
  {$ENDIF}
  FColor := AColor;
  FOrientation := gfoVertical;
  FColorTo := gcGray;
  FColorMirror := gcNull;
  FColorMirrorTo := gcNull;
end;

procedure TAdvCustomGraphicsFill.SetColor(const Value: TAdvGraphicsColor);
begin
  if FColor <> Value then
  begin
    FColor := Value;
    {$IFDEF CMNLIB}
    if FColor = clNone then
      FColor := gcNull
    else if FColor = clDefault then
      FColor := clBtnFace;
    {$ENDIF}
    Changed;
  end;
end;

procedure TAdvCustomGraphicsFill.SetColorTo(const Value: TAdvGraphicsColor);
begin
  if FColorTo <> Value then
  begin
    FColorTo := Value;
    {$IFDEF CMNLIB}
    if FColorTo = clNone then
      FColorTo := gcNull
    else if FColorTo = clDefault then
      FColorTo := clBtnFace;
    {$ENDIF}
    Changed;
  end;
end;

procedure TAdvCustomGraphicsFill.SetColorMirror(const Value: TAdvGraphicsColor);
begin
  if FColorMirror <> Value then
  begin
    FColorMirror := Value;
    {$IFDEF CMNLIB}
    if FColorMirror = clNone then
      FColorMirror := gcNull
    else if FColorMirror = clDefault then
      FColorMirror := clBtnFace;
    {$ENDIF}
    Changed;
  end;
end;

procedure TAdvCustomGraphicsFill.SetColorMirrorTo(const Value: TAdvGraphicsColor);
begin
  if FColorMirrorTo <> Value then
  begin
    FColorMirrorTo := Value;
    {$IFDEF CMNLIB}
    if FColorMirrorTo = clNone then
      FColorMirrorTo := gcNull
    else if FColorMirrorTo = clDefault then
      FColorMirrorTo := clBtnFace;
    {$ENDIF}
    Changed;
  end;
end;

procedure TAdvCustomGraphicsFill.SetKind(const Value: TAdvGraphicsFillKind);
begin
  if FKind <> Value then
  begin
    FKind := Value;
    Changed;
  end;
end;

procedure TAdvCustomGraphicsFill.SetOrientation(const Value: TAdvGraphicsFillOrientation);
begin
  if FOrientation <> Value then
  begin
    FOrientation := Value;
    Changed;
  end;
end;

{$IFDEF FMXLIB}
procedure TAdvCustomGraphicsFill.SetOpacity(const Value: Single);
begin
  if FOpacity <> Value then
  begin
    FOpacity := Value;
    Changed;
  end;
end;

function TAdvCustomGraphicsFill.IsOpacityStored: Boolean;
begin
  Result := Opacity <> 1;
end;

{$ENDIF}

{ TAdvCustomGraphicsStroke }

procedure TAdvCustomGraphicsStroke.Assign(Source: TPersistent);
begin
  if Source is TAdvCustomGraphicsStroke then
  begin
    FColor := (Source as TAdvCustomGraphicsStroke).Color;
    FKind := (Source as TAdvCustomGraphicsStroke).Kind;
    {$IFDEF FMXLIB}
    FOpacity := (Source as TAdvCustomGraphicsStroke).Opacity;
    {$ENDIF}
    FWidth := (Source as TAdvCustomGraphicsStroke).Width;
  end
  else if Source is TAdvCustomGraphicsFill then
  begin
    FColor := (Source as TAdvCustomGraphicsFill).Color;
    FKind := gskSolid;
    {$IFDEF FMXLIB}
    FOpacity := 1;
    {$ENDIF}
    FWidth := 1;
  end;
  Changed;
end;

procedure TAdvCustomGraphicsStroke.Changed;
begin
  if Assigned(OnChanged) then
    OnChanged(Self);
end;

constructor TAdvCustomGraphicsStroke.Create(const AKind: TAdvGraphicsStrokeKind = gskSolid; const AColor: TAdvGraphicsColor = gcSilver);
begin
  FKind := AKind;
  {$IFDEF FMXLIB}
  FOpacity := 1;
  {$ENDIF}
  FColor := AColor;
  FWidth := 1;
end;

function TAdvCustomGraphicsStroke.IsWidthStored: Boolean;
begin
  Result := Width <> 0;
end;

procedure TAdvCustomGraphicsStroke.SetColor(const Value: TAdvGraphicsColor);
begin
  if FColor <> Value then
  begin
    FColor := Value;
    {$IFDEF CMNLIB}
    if FColor = clNone then
      FColor := gcNull
    else if FColor = clDefault then
      FColor := clBtnFace;
    {$ENDIF}
    Changed;
  end;
end;

procedure TAdvCustomGraphicsStroke.SetKind(const Value: TAdvGraphicsStrokeKind);
begin
  if FKind <> Value then
  begin
    FKind := Value;
    Changed;
  end;
end;

{$IFDEF FMXLIB}
procedure TAdvCustomGraphicsStroke.SetOpacity(const Value: Single);
begin
  if FOpacity <> Value then
  begin
    FOpacity := Value;
    Changed;
  end;
end;

function TAdvCustomGraphicsStroke.IsOpacityStored: Boolean;
begin
  Result := Opacity <> 1;
end;
{$ENDIF}

procedure TAdvCustomGraphicsStroke.SetWidth(const Value: Single);
begin
  if FWidth <> Value then
  begin
    FWidth := Value;
    Changed;
  end;
end;

{ TAdvGraphicsPath }

constructor TAdvGraphicsPath.Create;
begin
  inherited Create;
  FPoints := TAdvGraphicsPathPoints.Create;
end;

destructor TAdvGraphicsPath.Destroy;
begin
  FPoints.Free;
  inherited;
end;

procedure TAdvGraphicsPath.Assign(Source: TPersistent);
var
  I: Integer;
begin
  if Source is TAdvGraphicsPath then
  begin
    FPoints.Count := TAdvGraphicsPath(Source).Count;
    for I := 0 to TAdvGraphicsPath(Source).Count - 1 do
      FPoints[I] := TAdvGraphicsPath(Source)[I];
  end
  else
    inherited
end;

function TAdvGraphicsPath.GetCount: Integer;
begin
  Result := FPoints.Count;
end;

function TAdvGraphicsPath.GetPoint(AIndex: Integer): TAdvGraphicsPathPoint;
begin
  Result := FPoints[AIndex];
end;

function TAdvGraphicsPath.LastPoint: TPointF;
begin
  if Count > 0 then
    Result := FPoints[FPoints.Count - 1].Point
  else
  begin
    Result := PointF(0, 0);
  end;
end;

procedure TAdvGraphicsPath.MoveTo(const P: TPointF);
var
  pt: TAdvGraphicsPathPoint;
begin
  pt.Kind := gppMoveTo;
  pt.Point := p;
  FPoints.Add(pt);
  FStartPoint := FPoints[FPoints.Count - 1].Point;
end;

procedure TAdvGraphicsPath.LineTo(const P: TPointF);
var
  pt: TAdvGraphicsPathPoint;
begin
  pt.Kind := gppLineTo;
  pt.Point := p;
  FPoints.Add(pt);
end;

procedure TAdvGraphicsPath.QuadCurveTo(const ControlPoint, EndPoint: TPointF);
const
  OneThird = 1 / 3;
  TwoThirds = 2 / 3;
var
  LP, CP1, CP2: TPointF;
begin
  LP := LastPoint;
  CP1.X := OneThird * LP.X + TwoThirds * ControlPoint.X;
  CP1.Y := OneThird * LP.Y + TwoThirds * ControlPoint.Y;
  CP2.X := TwoThirds * ControlPoint.X + OneThird * EndPoint.X;
  CP2.Y := TwoThirds * ControlPoint.Y + OneThird * EndPoint.Y;
  CurveTo(CP1, CP2, EndPoint);
end;

procedure TAdvGraphicsPath.CurveTo(const ControlPoint1, ControlPoint2, EndPoint: TPointF);
var
  pt: TAdvGraphicsPathPoint;
begin
  pt.Kind := gppCurveTo;
  pt.Point := ControlPoint1;
  FPoints.Add(pt);
  pt.Kind := gppCurveTo;
  pt.Point := ControlPoint2;
  FPoints.Add(pt);
  pt.Kind := gppCurveTo;
  pt.Point := EndPoint;
  FPoints.Add(pt);
end;

procedure TAdvGraphicsPath.SmoothCurveTo(const ControlPoint2, EndPoint: TPointF);
var
  ControlPoint1: TPointF;
begin
  if Count > 2 then
  begin
    ControlPoint1.X := LastPoint.X + (LastPoint.X - FPoints[FPoints.Count - 2].Point.X);
    ControlPoint1.Y := LastPoint.Y + (LastPoint.Y - FPoints[FPoints.Count - 2].Point.Y);
  end
  else
    ControlPoint1 := ControlPoint2;
  CurveTo(ControlPoint1, ControlPoint2, EndPoint);
end;

procedure TAdvGraphicsPath.ClosePath;
var
  pt: TAdvGraphicsPathPoint;
begin
  pt.Kind := gppClose;
  pt.Point := FStartPoint;
  FPoints.Add(pt);
end;

procedure TAdvGraphicsPath.AddPath(APath: TAdvGraphicsPath);
var
  I: Integer;
begin
  FPoints.Capacity := FPoints.Count + APath.Count;
  for I := 0 to APath.Count - 1 do
    FPoints.Add(APath.Points[I]);
end;

procedure TAdvGraphicsPath.Clear;
begin
  FPoints.Clear;
end;

procedure TAdvGraphicsPath.CalculateBezierCoefficients(const Bezier: TAdvGraphicsPathCubicBezier; out AX, BX, CX, AY, BY, CY: Single);
begin
  CX := 3 * (Bezier[1].X - Bezier[0].X);
  CY := 3 * (Bezier[1].Y - Bezier[0].Y);
  BX := 3 * (Bezier[2].X - Bezier[1].X) - CX;
  BY := 3 * (Bezier[2].Y - Bezier[1].Y) - CY;
  AX := Bezier[3].X - Bezier[0].X - CX - BX;
  AY := Bezier[3].Y - Bezier[0].Y - CY - BY;
end;

function TAdvGraphicsPath.PointOnBezier(const StartPoint: TPointF; const AX, BX, CX, AY, BY, CY, T: Single): TPointF;
var
  SquareT, CubeT: Single;
begin
  SquareT := T * T;
  CubeT := SquareT * T;
  Result.X := (AX * CubeT) + (BX * SquareT) + (CX * T) + StartPoint.X;
  Result.Y := (AY * CubeT) + (BY * SquareT) + (CY * T) + StartPoint.Y;
end;

function TAdvGraphicsPath.CreateBezier(const Bezier: TAdvGraphicsPathCubicBezier; const PointCount: Integer): TAdvGraphicsPathPolygon;
var
  AX, BX, CX, AY, BY, CY, DT, T: Single;
  I: Integer;
begin
  if PointCount = 0 then
    Exit;
  DT := 1 / (1 * PointCount - 1);
  T := 0;
  SetLength(Result, PointCount);
  CalculateBezierCoefficients(Bezier, AX, BX, CX, AY, BY, CY);
  for I := 0 to PointCount - 1 do
  begin
    Result[I] := PointOnBezier(Bezier[0], AX, BX, CX, AY, BY, CY, T);
    T := T + DT;
  end;
end;

procedure TAdvGraphicsPath.Flatten(const Flatness: Single);
var
  J, I: Integer;
  BPts: TAdvGraphicsPathPolygon;
  B: TAdvGraphicsPathCubicBezier;
  F, Len: Single;
  SegCount: Integer;
  OldPathData: TAdvGraphicsPathPoints;
  CurPoint: TPointF;
  x: TPointF;
begin
  if FPoints.Count > 0 then
  begin
    F := Max(Flatness, 0.05);
    OldPathData := TAdvGraphicsPathPoints.Create;
    try
      OldPathData.Count := FPoints.Count;
      for J := 0 to FPoints.Count - 1 do
        OldPathData.Add(FPoints[J]);
      FPoints.Clear;
      J := 0;
      while J < OldPathData.Count do
      begin
        case OldPathData[J].Kind of
          gppMoveTo:
            begin
              MoveTo(OldPathData[J].Point);
              CurPoint := OldPathData[J].Point;
            end;
          gppLineTo:
            begin
              LineTo(OldPathData[J].Point);
              CurPoint := OldPathData[J].Point;
            end;
          gppCurveTo:
            begin
              B[0] := CurPoint;
              B[1] := OldPathData[J].Point;
              Inc(J);
              B[2] := OldPathData[J].Point;
              Inc(J);
              B[3] := OldPathData[J].Point;
              BPts := CreateBezier(B, 6);
              Len := 0;
              for I := 0 to High(BPts) - 1 do
              begin
                x.X := BPts[I].X - BPts[I + 1].X;
                x.Y := BPts[I].Y - BPts[I + 1].Y;
                Len := Len + GetPointLength(x);
              end;
              SegCount := Round(Len / F);
              if SegCount < 2 then
                LineTo(B[3])
              else
              begin
                BPts := CreateBezier(B, SegCount);
                for I := 0 to High(BPts) do
                  LineTo(BPts[I]);
                CurPoint := OldPathData[J].Point;
              end;
            end;
          gppClose:
            ClosePath;
        end;
        Inc(J);
      end;
    finally
      OldPathData.Free;
    end;
  end;
end;

procedure TAdvGraphicsPath.FlattenToPolygon(var Polygon: TAdvGraphicsPathPolygon; const Flatness: Single = 0.25);

  procedure AddPoint(const P: TPointF);
  begin
    if (Length(Polygon) > 0) and (SameValue(P.X, Polygon[High(Polygon)].X, PathPosition) and SameValue(P.Y,
      Polygon[High(Polygon)].Y, PathPosition)) then
      Exit;
    SetLength(Polygon, Length(Polygon) + 1);
    Polygon[High(Polygon)] := P;
  end;

var
  J, I: Integer;
  BPts: TAdvGraphicsPathPolygon;
  B: TAdvGraphicsPathCubicBezier;
  SP, CurPoint, X: TPointF;
  F, Len: Single;
  SegCount: Integer;
begin
  SetLength(Polygon, 0);
  if FPoints.Count > 0 then
  begin
    F := Max(Flatness, 0.05);
    J := 0;
    while J < FPoints.Count do
    begin
      case FPoints[J].Kind of
        gppMoveTo:
          begin
            if Length(Polygon) > 0 then
              AddPoint(PointF($FFFFFF, $FFFFFF));
            AddPoint(FPoints[J].Point);
            CurPoint := FPoints[J].Point;
            SP := CurPoint;
          end;
        gppLineTo:
          begin
            AddPoint(FPoints[J].Point);
            CurPoint := FPoints[J].Point;
          end;
        gppCurveTo:
          begin
            B[0] := CurPoint;
            B[1] := FPoints[J].Point;
            Inc(J);
            B[2] := FPoints[J].Point;
            Inc(J);
            B[3] := FPoints[J].Point;
            BPts := CreateBezier(B, 6);
            Len := 0;
            for I := 0 to High(BPts) - 1 do
            begin
              x.X := BPts[I].X - BPts[I + 1].X;
              x.Y := BPts[I].Y - BPts[I + 1].Y;
              Len := Len + GetPointLength(x);
            end;
            SegCount := Round(Len / F);
            if SegCount < 2 then
            begin
              AddPoint(B[0]);
              AddPoint(B[3]);
            end
            else
            begin
              BPts := CreateBezier(B, SegCount);
              for I := 0 to High(BPts) do
                AddPoint(BPts[I]);
            end;
            CurPoint := FPoints[J].Point;
          end;
        gppClose:
          begin
            AddPoint(SP);
          end;
      end;
      Inc(J);
    end;
  end;
end;

procedure TAdvGraphicsPath.AddEllipse(const ARect: TRectF);
var
  CX, CY, PX, PY: Single;
  c: Single;
begin
  c := 0.5522847498;
  CX := (ARect.Left + ARect.Right) / 2;
  CY := (ARect.Top + ARect.Bottom) / 2;
  PX := c * (ARect.Width / 2);
  PY := c * (ARect.Height / 2);
  MoveTo(PointF(ARect.Left, CY));
  CurveTo(PointF(ARect.Left, CY - PY), PointF(CX - PX, ARect.Top), PointF(CX, ARect.Top));
  CurveTo(PointF(CX + PX, ARect.Top), PointF(ARect.Right, CY - PY), PointF(ARect.Right, CY));
  CurveTo(PointF(ARect.Right, CY + PY), PointF(CX + PX, ARect.Bottom), PointF(CX, ARect.Bottom));
  CurveTo(PointF(CX - PX, ARect.Bottom), PointF(ARect.Left, CY + PY), PointF(ARect.Left, CY));
end;

procedure TAdvGraphicsPath.AddRectangle(const ARect: TRectF);
begin
  MoveTo(ARect.TopLeft);
  LineTo(PointF(ARect.Right, ARect.Top));
  LineTo(ARect.BottomRight);
  LineTo(PointF(ARect.Left, ARect.Bottom));
  ClosePath;
end;

procedure DrawArcWithBezier(Path: TAdvGraphicsPath; CenterX, CenterY, RadiusX, RadiusY, StartAngle, SweepRange: Single;
  UseMoveTo: Boolean);
var
  Coord: array of TPointF;
  Pts: array of TPointF;
  A, X, Y: Single;
  {$IFDEF LCLLIB}
  C, B, CC, SS: Extended;
  {$ELSE}
  C, B, CC, SS: Single;
  {$ENDIF}
  I: Integer;
begin
  if SweepRange = 0 then
  begin
    if UseMoveTo then
    begin
      if Path.FPoints.Count < 1 then
        Path.MoveTo(PointF(CenterX + RadiusX * Cos(StartAngle), CenterY - RadiusY * Sin(StartAngle)))
      else
        Path.LineTo(PointF(CenterX + RadiusX * Cos(StartAngle), CenterY - RadiusY * Sin(StartAngle)));
    end;
    Path.LineTo(PointF(CenterX + RadiusX * Cos(StartAngle), CenterY - RadiusY * Sin(StartAngle)));
    Exit;
  end;
  SinCos(SweepRange / 2, B, C);
  A := 1 - C;
  X := A * 4 / 3;
  Y := B - X * C / B;
  SinCos(StartAngle + SweepRange / 2, SS, CC);
  SetLength(Coord, 4);
  Coord[0] := PointF(C, -B);
  Coord[1] := PointF(C + X, -Y);
  Coord[2] := PointF(C + X, Y);
  Coord[3] := PointF(C, B);
  SetLength(Pts, 4);
  for I := 0 to 3 do
  begin
    Pts[I] := PointF(CenterX + RadiusX * (Coord[I].X * CC - Coord[I].Y * SS), CenterY + RadiusY * (Coord[I].X *
      SS + Coord[I].Y * CC));
  end;
  if UseMoveTo then
  begin
    if Path.FPoints.Count < 1 then
      Path.MoveTo(Pts[0])
    else
      Path.LineTo(Pts[0]);
  end;
  Path.CurveTo(Pts[1], Pts[2], Pts[3]);
end;

procedure TAdvGraphicsPath.AddArc(const Center, Radius: TPointF; StartAngle, SweepAngle: Single);
const
  BezierArcAngleEpsilon = 0.01;
  MinSweepAngle = 1E-10;
var
  UseMoveTo: Boolean;
  I: Integer;
  F: Single;
  TotalSweep, LocalSweep, PrevSweep: Single;
  Done: Boolean;
begin
  StartAngle := DegToRad(StartAngle);
  SweepAngle := DegToRad(SweepAngle);
  I := Trunc(StartAngle / (2 * Pi));
  F := StartAngle - (I * 2 * Pi);
  StartAngle := F;
  if SweepAngle >= 2 * Pi then
    SweepAngle := 2 * Pi;
  if SweepAngle <= -2 * Pi then
    SweepAngle := -2 * Pi;
  if Abs(SweepAngle) < MinSweepAngle then
    Exit;
  TotalSweep := 0;
  Done := False;
  UseMoveTo := True;
  repeat
    if SweepAngle < 0 then
    begin
      PrevSweep := TotalSweep;
      LocalSweep := -Pi / 2;
      TotalSweep := TotalSweep - (Pi / 2);
      if TotalSweep <= SweepAngle + BezierArcAngleEpsilon then
      begin
        LocalSweep := SweepAngle - PrevSweep;
        Done := True;
      end;
    end
    else
    begin
      PrevSweep := TotalSweep;
      LocalSweep := Pi / 2;
      TotalSweep := TotalSweep + (Pi / 2);
      if TotalSweep >= SweepAngle - BezierArcAngleEpsilon then
      begin
        LocalSweep := SweepAngle - PrevSweep;
        Done := True;
      end;
    end;
    DrawArcWithBezier(Self, Center.X, Center.Y, Radius.X, Radius.Y, StartAngle, LocalSweep, UseMoveTo);
    UseMoveTo := False;
    StartAngle := StartAngle + LocalSweep;
  until Done;
end;

{ TAdvGraphicsPathPoint }

{$IFDEF LCLLIB}
class operator TAdvGraphicsPathPoint.=(z1, z2: TAdvGraphicsPathPoint)b: boolean;
begin
  Result := z1 = z2;
end;
{$ENDIF}

{ TAdvGraphicsColorObject }

constructor TAdvGraphicsColorObject.Create(AColor: TAdvGraphicsColor);
begin
  FColor := AColor;
end;

procedure DestroyColorLookup;
var
  I: Integer;
begin
  {$IFDEF FMXLIB}
  for I := 0 to FColorLookup.Count - 1 do
    FColorLookup.Objects[I].DisposeOf;
  {$ELSE}
  for I := 0 to FColorLookup.Count - 1 do
    FColorLookup.Objects[I].Free;
  {$ENDIF}

  FColorLookup.Free;
end;

initialization
begin
  fcolorlookup := TStringList.Create;
  fcolorlookup.addobject('aliceblue', TAdvGraphicsColorObject.Create(gcaliceblue));
  fcolorlookup.addobject('antiquewhite', TAdvGraphicsColorObject.Create(gcantiquewhite));
  fcolorlookup.addobject('aqua', TAdvGraphicsColorObject.Create(gcaqua));
  fcolorlookup.addobject('aquamarine', TAdvGraphicsColorObject.Create(gcaquamarine));
  fcolorlookup.addobject('azure', TAdvGraphicsColorObject.Create(gcazure));
  fcolorlookup.addobject('beige', TAdvGraphicsColorObject.Create(gcbeige));
  fcolorlookup.addobject('bisque', TAdvGraphicsColorObject.Create(gcbisque));
  fcolorlookup.addobject('black', TAdvGraphicsColorObject.Create(gcblack));
  fcolorlookup.addobject('blanchedalmond', TAdvGraphicsColorObject.Create(gcblanchedalmond));
  fcolorlookup.addobject('blue', TAdvGraphicsColorObject.Create(gcblue));
  fcolorlookup.addobject('blueviolet', TAdvGraphicsColorObject.Create(gcblueviolet));
  fcolorlookup.addobject('brown', TAdvGraphicsColorObject.Create(gcbrown));
  fcolorlookup.addobject('burlywood', TAdvGraphicsColorObject.Create(gcburlywood));
  fcolorlookup.addobject('cadetblue', TAdvGraphicsColorObject.Create(gccadetblue));
  fcolorlookup.addobject('chartreuse', TAdvGraphicsColorObject.Create(gcchartreuse));
  fcolorlookup.addobject('chocolate', TAdvGraphicsColorObject.Create(gcchocolate));
  fcolorlookup.addobject('coral', TAdvGraphicsColorObject.Create(gccoral));
  fcolorlookup.addobject('cornflowerblue', TAdvGraphicsColorObject.Create(gccornflowerblue));
  fcolorlookup.addobject('cornsilk', TAdvGraphicsColorObject.Create(gccornsilk));
  fcolorlookup.addobject('crimson', TAdvGraphicsColorObject.Create(gccrimson));
  fcolorlookup.addobject('cyan', TAdvGraphicsColorObject.Create(gccyan));
  fcolorlookup.addobject('darkblue', TAdvGraphicsColorObject.Create(gcdarkblue));
  fcolorlookup.addobject('darkcyan', TAdvGraphicsColorObject.Create(gcdarkcyan));
  fcolorlookup.addobject('darkgoldenrod', TAdvGraphicsColorObject.Create(gcdarkgoldenrod));
  fcolorlookup.addobject('darkgray', TAdvGraphicsColorObject.Create(gcdarkgray));
  fcolorlookup.addobject('darkgreen', TAdvGraphicsColorObject.Create(gcdarkgreen));
  fcolorlookup.addobject('darkgrey', TAdvGraphicsColorObject.Create(gcdarkgrey));
  fcolorlookup.addobject('darkkhaki', TAdvGraphicsColorObject.Create(gcdarkkhaki));
  fcolorlookup.addobject('darkmagenta', TAdvGraphicsColorObject.Create(gcdarkmagenta));
  fcolorlookup.addobject('darkolivegreen', TAdvGraphicsColorObject.Create(gcdarkolivegreen));
  fcolorlookup.addobject('darkorange', TAdvGraphicsColorObject.Create(gcdarkorange));
  fcolorlookup.addobject('darkorchid', TAdvGraphicsColorObject.Create(gcdarkorchid));
  fcolorlookup.addobject('darkred', TAdvGraphicsColorObject.Create(gcdarkred));
  fcolorlookup.addobject('darksalmon', TAdvGraphicsColorObject.Create(gcdarksalmon));
  fcolorlookup.addobject('darkseagreen', TAdvGraphicsColorObject.Create(gcdarkseagreen));
  fcolorlookup.addobject('darkslateblue', TAdvGraphicsColorObject.Create(gcdarkslateblue));
  fcolorlookup.addobject('darkslategray', TAdvGraphicsColorObject.Create(gcdarkslategray));
  fcolorlookup.addobject('darkslategrey', TAdvGraphicsColorObject.Create(gcdarkslategrey));
  fcolorlookup.addobject('darkturquoise', TAdvGraphicsColorObject.Create(gcdarkturquoise));
  fcolorlookup.addobject('darkviolet', TAdvGraphicsColorObject.Create(gcdarkviolet));
  fcolorlookup.addobject('deeppink', TAdvGraphicsColorObject.Create(gcdeeppink));
  fcolorlookup.addobject('deepskyblue', TAdvGraphicsColorObject.Create(gcdeepskyblue));
  fcolorlookup.addobject('dimgray', TAdvGraphicsColorObject.Create(gcdimgray));
  fcolorlookup.addobject('dimgrey', TAdvGraphicsColorObject.Create(gcdimgrey));
  fcolorlookup.addobject('dodgerblue', TAdvGraphicsColorObject.Create(gcdodgerblue));
  fcolorlookup.addobject('firebrick', TAdvGraphicsColorObject.Create(gcfirebrick));
  fcolorlookup.addobject('floralwhite', TAdvGraphicsColorObject.Create(gcfloralwhite));
  fcolorlookup.addobject('forestgreen', TAdvGraphicsColorObject.Create(gcforestgreen));
  fcolorlookup.addobject('fuchsia', TAdvGraphicsColorObject.Create(gcfuchsia));
  fcolorlookup.addobject('gainsboro', TAdvGraphicsColorObject.Create(gcgainsboro));
  fcolorlookup.addobject('ghostwhite', TAdvGraphicsColorObject.Create(gcghostwhite));
  fcolorlookup.addobject('gold', TAdvGraphicsColorObject.Create(gcgold));
  fcolorlookup.addobject('goldenrod', TAdvGraphicsColorObject.Create(gcgoldenrod));
  fcolorlookup.addobject('gray', TAdvGraphicsColorObject.Create(gcgray));
  fcolorlookup.addobject('green', TAdvGraphicsColorObject.Create(gcgreen));
  fcolorlookup.addobject('greenyellow', TAdvGraphicsColorObject.Create(gcgreenyellow));
  fcolorlookup.addobject('grey', TAdvGraphicsColorObject.Create(gcgrey));
  fcolorlookup.addobject('honeydew', TAdvGraphicsColorObject.Create(gchoneydew));
  fcolorlookup.addobject('hotpink', TAdvGraphicsColorObject.Create(gchotpink));
  fcolorlookup.addobject('indianred', TAdvGraphicsColorObject.Create(gcindianred));
  fcolorlookup.addobject('indigo', TAdvGraphicsColorObject.Create(gcindigo));
  fcolorlookup.addobject('ivory', TAdvGraphicsColorObject.Create(gcivory));
  fcolorlookup.addobject('khaki', TAdvGraphicsColorObject.Create(gckhaki));
  fcolorlookup.addobject('lavender', TAdvGraphicsColorObject.Create(gcLavender));
  fcolorlookup.addobject('lavenderblush', TAdvGraphicsColorObject.Create(gcLavenderblush));
  fcolorlookup.addobject('lawngreen', TAdvGraphicsColorObject.Create(gcLawngreen));
  fcolorlookup.addobject('lemonchiffon', TAdvGraphicsColorObject.Create(gclemonchiffon));
  fcolorlookup.addobject('lightblue', TAdvGraphicsColorObject.Create(gclightblue));
  fcolorlookup.addobject('lightcoral', TAdvGraphicsColorObject.Create(gclightcoral));
  fcolorlookup.addobject('lightcyan', TAdvGraphicsColorObject.Create(gclightcyan));
  fcolorlookup.addobject('lightgoldenrodyellow', TAdvGraphicsColorObject.Create(gclightgoldenrodyellow));
  fcolorlookup.addobject('lightgray', TAdvGraphicsColorObject.Create(gclightgray));
  fcolorlookup.addobject('lightgreen', TAdvGraphicsColorObject.Create(gclightgreen));
  fcolorlookup.addobject('lightgrey', TAdvGraphicsColorObject.Create(gclightgrey));
  fcolorlookup.addobject('lightpink', TAdvGraphicsColorObject.Create(gclightpink));
  fcolorlookup.addobject('lightsalmon', TAdvGraphicsColorObject.Create(gclightsalmon));
  fcolorlookup.addobject('lightseagreen', TAdvGraphicsColorObject.Create(gclightseagreen));
  fcolorlookup.addobject('lightskyblue', TAdvGraphicsColorObject.Create(gclightskyblue));
  fcolorlookup.addobject('lightslategray', TAdvGraphicsColorObject.Create(gclightslategray));
  fcolorlookup.addobject('lightslategrey', TAdvGraphicsColorObject.Create(gclightslategrey));
  fcolorlookup.addobject('lightsteelblue', TAdvGraphicsColorObject.Create(gclightsteelblue));
  fcolorlookup.addobject('lightyellow', TAdvGraphicsColorObject.Create(gclightyellow));
  fcolorlookup.addobject('lime', TAdvGraphicsColorObject.Create(gclime));
  fcolorlookup.addobject('limegreen', TAdvGraphicsColorObject.Create(gclimegreen));
  fcolorlookup.addobject('linen', TAdvGraphicsColorObject.Create(gclinen));
  fcolorlookup.addobject('magenta', TAdvGraphicsColorObject.Create(gcmagenta));
  fcolorlookup.addobject('maroon', TAdvGraphicsColorObject.Create(gcmaroon));
  fcolorlookup.addobject('mediumaquamarine', TAdvGraphicsColorObject.Create(gcmediumaquamarine));
  fcolorlookup.addobject('mediumblue', TAdvGraphicsColorObject.Create(gcmediumblue));
  fcolorlookup.addobject('mediumorchid', TAdvGraphicsColorObject.Create(gcmediumorchid));
  fcolorlookup.addobject('mediumpurple', TAdvGraphicsColorObject.Create(gcmediumpurple));
  fcolorlookup.addobject('mediumseagreen', TAdvGraphicsColorObject.Create(gcmediumseagreen));
  fcolorlookup.addobject('mediumslateblue', TAdvGraphicsColorObject.Create(gcmediumslateblue));
  fcolorlookup.addobject('mediumspringgreen', TAdvGraphicsColorObject.Create(gcmediumspringgreen));
  fcolorlookup.addobject('mediumturquoise', TAdvGraphicsColorObject.Create(gcmediumturquoise));
  fcolorlookup.addobject('mediumvioletred', TAdvGraphicsColorObject.Create(gcmediumvioletred));
  fcolorlookup.addobject('midnightblue', TAdvGraphicsColorObject.Create(gcmidnightblue));
  fcolorlookup.addobject('mintcream', TAdvGraphicsColorObject.Create(gcmintcream));
  fcolorlookup.addobject('mistyrose', TAdvGraphicsColorObject.Create(gcmistyrose));
  fcolorlookup.addobject('moccasin', TAdvGraphicsColorObject.Create(gcmoccasin));
  fcolorlookup.addobject('navajowhite', TAdvGraphicsColorObject.Create(gcnavajowhite));
  fcolorlookup.addobject('navy', TAdvGraphicsColorObject.Create(gcnavy));
  fcolorlookup.addobject('oldlace', TAdvGraphicsColorObject.Create(gcoldlace));
  fcolorlookup.addobject('olive', TAdvGraphicsColorObject.Create(gcolive));
  fcolorlookup.addobject('olivedrab', TAdvGraphicsColorObject.Create(gcolivedrab));
  fcolorlookup.addobject('orange', TAdvGraphicsColorObject.Create(gcorange));
  fcolorlookup.addobject('orangered', TAdvGraphicsColorObject.Create(gcorangered));
  fcolorlookup.addobject('orchid', TAdvGraphicsColorObject.Create(gcorchid));
  fcolorlookup.addobject('palegoldenrod', TAdvGraphicsColorObject.Create(gcpalegoldenrod));
  fcolorlookup.addobject('palegreen', TAdvGraphicsColorObject.Create(gcpalegreen));
  fcolorlookup.addobject('paleturquoise', TAdvGraphicsColorObject.Create(gcpaleturquoise));
  fcolorlookup.addobject('palevioletred', TAdvGraphicsColorObject.Create(gcpalevioletred));
  fcolorlookup.addobject('papayawhip', TAdvGraphicsColorObject.Create(gcpapayawhip));
  fcolorlookup.addobject('peachpuff', TAdvGraphicsColorObject.Create(gcpeachpuff));
  fcolorlookup.addobject('peru', TAdvGraphicsColorObject.Create(gcperu));
  fcolorlookup.addobject('pink', TAdvGraphicsColorObject.Create(gcpink));
  fcolorlookup.addobject('plum', TAdvGraphicsColorObject.Create(gcplum));
  fcolorlookup.addobject('powderblue', TAdvGraphicsColorObject.Create(gcpowderblue));
  fcolorlookup.addobject('purple', TAdvGraphicsColorObject.Create(gcpurple));
  fcolorlookup.addobject('red', TAdvGraphicsColorObject.Create(gcred));
  fcolorlookup.addobject('rosybrown', TAdvGraphicsColorObject.Create(gcrosybrown));
  fcolorlookup.addobject('royalblue', TAdvGraphicsColorObject.Create(gcroyalblue));
  fcolorlookup.addobject('saddlebrown', TAdvGraphicsColorObject.Create(gcsaddlebrown));
  fcolorlookup.addobject('salmon', TAdvGraphicsColorObject.Create(gcsalmon));
  fcolorlookup.addobject('sandybrown', TAdvGraphicsColorObject.Create(gcsandybrown));
  fcolorlookup.addobject('seagreen', TAdvGraphicsColorObject.Create(gcseagreen));
  fcolorlookup.addobject('seashell', TAdvGraphicsColorObject.Create(gcseashell));
  fcolorlookup.addobject('sienna', TAdvGraphicsColorObject.Create(gcsienna));
  fcolorlookup.addobject('skyblue', TAdvGraphicsColorObject.Create(gcskyblue));
  fcolorlookup.addobject('slateblue', TAdvGraphicsColorObject.Create(gcslateblue));
  fcolorlookup.addobject('slategray', TAdvGraphicsColorObject.Create(gcslategray));
  fcolorlookup.addobject('slategrey', TAdvGraphicsColorObject.Create(gcslategrey));
  fcolorlookup.addobject('snow', TAdvGraphicsColorObject.Create(gcsnow));
  fcolorlookup.addobject('springgreen', TAdvGraphicsColorObject.Create(gcspringgreen));
  fcolorlookup.addobject('steelblue', TAdvGraphicsColorObject.Create(gcsteelblue));
  fcolorlookup.addobject('violet', TAdvGraphicsColorObject.Create(gcviolet));
  fcolorlookup.addobject('thistle', TAdvGraphicsColorObject.Create(gcthistle));
  fcolorlookup.addobject('tan', TAdvGraphicsColorObject.Create(gctan));
  fcolorlookup.addobject('tomato', TAdvGraphicsColorObject.Create(gctomato));
  fcolorlookup.addobject('turquoise', TAdvGraphicsColorObject.Create(gcturquoise));
  fcolorlookup.addobject('wheat', TAdvGraphicsColorObject.Create(gcwheat));
  fcolorlookup.addobject('whitesmoke', TAdvGraphicsColorObject.Create(gcwhitesmoke));
  fcolorlookup.addobject('yellowgreen', TAdvGraphicsColorObject.Create(gcyellowgreen));
  fcolorlookup.addobject('red', TAdvGraphicsColorObject.Create(gcred));
  fcolorlookup.addobject('black', TAdvGraphicsColorObject.Create(gcblack));
  fcolorlookup.addobject('blue', TAdvGraphicsColorObject.Create(gcblue));
  fcolorlookup.addobject('green', TAdvGraphicsColorObject.Create(gcgreen));
  fcolorlookup.addobject('aqua', TAdvGraphicsColorObject.Create(gcaqua));
  fcolorlookup.addobject('yellow', TAdvGraphicsColorObject.Create(gcyellow));
  fcolorlookup.addobject('fuchsia', TAdvGraphicsColorObject.Create(gcfuchsia));
  fcolorlookup.addobject('white', TAdvGraphicsColorObject.Create(gcwhite));
  fcolorlookup.addobject('lime', TAdvGraphicsColorObject.Create(gclime));
  fcolorlookup.addobject('silver', TAdvGraphicsColorObject.Create(gcsilver));
  fcolorlookup.addobject('gray', TAdvGraphicsColorObject.Create(gcgray));
  fcolorlookup.addobject('olive', TAdvGraphicsColorObject.Create(gcolive));
  fcolorlookup.addobject('navy', TAdvGraphicsColorObject.Create(gcnavy));
  fcolorlookup.addobject('purple', TAdvGraphicsColorObject.Create(gcpurple));
  fcolorlookup.addobject('teal', TAdvGraphicsColorObject.Create(gcteal));
  fcolorlookup.addobject('orange', TAdvGraphicsColorObject.Create(gcorange));
  fcolorlookup.addobject('maroon', TAdvGraphicsColorObject.Create(gcmaroon));
  FColorLookup.Sort;
end;

finalization
begin
  DestroyColorLookup;
end;

end.
