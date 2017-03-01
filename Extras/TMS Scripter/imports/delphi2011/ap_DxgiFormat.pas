{***************************************************************************}
{ This source code was generated automatically by                           }
{ Pas file import tool for Scripter Studio (Pro)                            }
{                                                                           }
{ Scripter Studio and Pas file import tool for Scripter Studio              }
{ written by TMS Software                                                   }
{            copyright � 1997 - 2010                                        }
{            Email : info@tmssoftware.com                                   }
{            Web : http://www.tmssoftware.com                               }
{***************************************************************************}
//unit ap_DxgiFormat;

interface

uses
  Windows,
  DxgiFormat,
  Variants,
  atScript;

{$WARNINGS OFF}

type
  TatDxgiFormatLibrary = class(TatScripterLibrary)
    procedure Init; override;
    class function LibraryName: string; override;
  end;




implementation



procedure TatDxgiFormatLibrary.Init;
begin
  With Scripter.DefineClass(ClassType) do
  begin
    AddConstant('DXGI_FORMAT_UNKNOWN',DXGI_FORMAT_UNKNOWN);
    AddConstant('DXGI_FORMAT_R32G32B32A32_TYPELESS',DXGI_FORMAT_R32G32B32A32_TYPELESS);
    AddConstant('DXGI_FORMAT_R32G32B32A32_FLOAT',DXGI_FORMAT_R32G32B32A32_FLOAT);
    AddConstant('DXGI_FORMAT_R32G32B32A32_UINT',DXGI_FORMAT_R32G32B32A32_UINT);
    AddConstant('DXGI_FORMAT_R32G32B32A32_SINT',DXGI_FORMAT_R32G32B32A32_SINT);
    AddConstant('DXGI_FORMAT_R32G32B32_TYPELESS',DXGI_FORMAT_R32G32B32_TYPELESS);
    AddConstant('DXGI_FORMAT_R32G32B32_FLOAT',DXGI_FORMAT_R32G32B32_FLOAT);
    AddConstant('DXGI_FORMAT_R32G32B32_UINT',DXGI_FORMAT_R32G32B32_UINT);
    AddConstant('DXGI_FORMAT_R32G32B32_SINT',DXGI_FORMAT_R32G32B32_SINT);
    AddConstant('DXGI_FORMAT_R16G16B16A16_TYPELESS',DXGI_FORMAT_R16G16B16A16_TYPELESS);
    AddConstant('DXGI_FORMAT_R16G16B16A16_FLOAT',DXGI_FORMAT_R16G16B16A16_FLOAT);
    AddConstant('DXGI_FORMAT_R16G16B16A16_UNORM',DXGI_FORMAT_R16G16B16A16_UNORM);
    AddConstant('DXGI_FORMAT_R16G16B16A16_UINT',DXGI_FORMAT_R16G16B16A16_UINT);
    AddConstant('DXGI_FORMAT_R16G16B16A16_SNORM',DXGI_FORMAT_R16G16B16A16_SNORM);
    AddConstant('DXGI_FORMAT_R16G16B16A16_SINT',DXGI_FORMAT_R16G16B16A16_SINT);
    AddConstant('DXGI_FORMAT_R32G32_TYPELESS',DXGI_FORMAT_R32G32_TYPELESS);
    AddConstant('DXGI_FORMAT_R32G32_FLOAT',DXGI_FORMAT_R32G32_FLOAT);
    AddConstant('DXGI_FORMAT_R32G32_UINT',DXGI_FORMAT_R32G32_UINT);
    AddConstant('DXGI_FORMAT_R32G32_SINT',DXGI_FORMAT_R32G32_SINT);
    AddConstant('DXGI_FORMAT_R32G8X24_TYPELESS',DXGI_FORMAT_R32G8X24_TYPELESS);
    AddConstant('DXGI_FORMAT_D32_FLOAT_S8X24_UINT',DXGI_FORMAT_D32_FLOAT_S8X24_UINT);
    AddConstant('DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS',DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS);
    AddConstant('DXGI_FORMAT_X32_TYPELESS_G8X24_UINT',DXGI_FORMAT_X32_TYPELESS_G8X24_UINT);
    AddConstant('DXGI_FORMAT_R10G10B10A2_TYPELESS',DXGI_FORMAT_R10G10B10A2_TYPELESS);
    AddConstant('DXGI_FORMAT_R10G10B10A2_UNORM',DXGI_FORMAT_R10G10B10A2_UNORM);
    AddConstant('DXGI_FORMAT_R10G10B10A2_UINT',DXGI_FORMAT_R10G10B10A2_UINT);
    AddConstant('DXGI_FORMAT_R11G11B10_FLOAT',DXGI_FORMAT_R11G11B10_FLOAT);
    AddConstant('DXGI_FORMAT_R8G8B8A8_TYPELESS',DXGI_FORMAT_R8G8B8A8_TYPELESS);
    AddConstant('DXGI_FORMAT_R8G8B8A8_UNORM',DXGI_FORMAT_R8G8B8A8_UNORM);
    AddConstant('DXGI_FORMAT_R8G8B8A8_UNORM_SRGB',DXGI_FORMAT_R8G8B8A8_UNORM_SRGB);
    AddConstant('DXGI_FORMAT_R8G8B8A8_UINT',DXGI_FORMAT_R8G8B8A8_UINT);
    AddConstant('DXGI_FORMAT_R8G8B8A8_SNORM',DXGI_FORMAT_R8G8B8A8_SNORM);
    AddConstant('DXGI_FORMAT_R8G8B8A8_SINT',DXGI_FORMAT_R8G8B8A8_SINT);
    AddConstant('DXGI_FORMAT_R16G16_TYPELESS',DXGI_FORMAT_R16G16_TYPELESS);
    AddConstant('DXGI_FORMAT_R16G16_FLOAT',DXGI_FORMAT_R16G16_FLOAT);
    AddConstant('DXGI_FORMAT_R16G16_UNORM',DXGI_FORMAT_R16G16_UNORM);
    AddConstant('DXGI_FORMAT_R16G16_UINT',DXGI_FORMAT_R16G16_UINT);
    AddConstant('DXGI_FORMAT_R16G16_SNORM',DXGI_FORMAT_R16G16_SNORM);
    AddConstant('DXGI_FORMAT_R16G16_SINT',DXGI_FORMAT_R16G16_SINT);
    AddConstant('DXGI_FORMAT_R32_TYPELESS',DXGI_FORMAT_R32_TYPELESS);
    AddConstant('DXGI_FORMAT_D32_FLOAT',DXGI_FORMAT_D32_FLOAT);
    AddConstant('DXGI_FORMAT_R32_FLOAT',DXGI_FORMAT_R32_FLOAT);
    AddConstant('DXGI_FORMAT_R32_UINT',DXGI_FORMAT_R32_UINT);
    AddConstant('DXGI_FORMAT_R32_SINT',DXGI_FORMAT_R32_SINT);
    AddConstant('DXGI_FORMAT_R24G8_TYPELESS',DXGI_FORMAT_R24G8_TYPELESS);
    AddConstant('DXGI_FORMAT_D24_UNORM_S8_UINT',DXGI_FORMAT_D24_UNORM_S8_UINT);
    AddConstant('DXGI_FORMAT_R24_UNORM_X8_TYPELESS',DXGI_FORMAT_R24_UNORM_X8_TYPELESS);
    AddConstant('DXGI_FORMAT_X24_TYPELESS_G8_UINT',DXGI_FORMAT_X24_TYPELESS_G8_UINT);
    AddConstant('DXGI_FORMAT_R8G8_TYPELESS',DXGI_FORMAT_R8G8_TYPELESS);
    AddConstant('DXGI_FORMAT_R8G8_UNORM',DXGI_FORMAT_R8G8_UNORM);
    AddConstant('DXGI_FORMAT_R8G8_UINT',DXGI_FORMAT_R8G8_UINT);
    AddConstant('DXGI_FORMAT_R8G8_SNORM',DXGI_FORMAT_R8G8_SNORM);
    AddConstant('DXGI_FORMAT_R8G8_SINT',DXGI_FORMAT_R8G8_SINT);
    AddConstant('DXGI_FORMAT_R16_TYPELESS',DXGI_FORMAT_R16_TYPELESS);
    AddConstant('DXGI_FORMAT_R16_FLOAT',DXGI_FORMAT_R16_FLOAT);
    AddConstant('DXGI_FORMAT_D16_UNORM',DXGI_FORMAT_D16_UNORM);
    AddConstant('DXGI_FORMAT_R16_UNORM',DXGI_FORMAT_R16_UNORM);
    AddConstant('DXGI_FORMAT_R16_UINT',DXGI_FORMAT_R16_UINT);
    AddConstant('DXGI_FORMAT_R16_SNORM',DXGI_FORMAT_R16_SNORM);
    AddConstant('DXGI_FORMAT_R16_SINT',DXGI_FORMAT_R16_SINT);
    AddConstant('DXGI_FORMAT_R8_TYPELESS',DXGI_FORMAT_R8_TYPELESS);
    AddConstant('DXGI_FORMAT_R8_UNORM',DXGI_FORMAT_R8_UNORM);
    AddConstant('DXGI_FORMAT_R8_UINT',DXGI_FORMAT_R8_UINT);
    AddConstant('DXGI_FORMAT_R8_SNORM',DXGI_FORMAT_R8_SNORM);
    AddConstant('DXGI_FORMAT_R8_SINT',DXGI_FORMAT_R8_SINT);
    AddConstant('DXGI_FORMAT_A8_UNORM',DXGI_FORMAT_A8_UNORM);
    AddConstant('DXGI_FORMAT_R1_UNORM',DXGI_FORMAT_R1_UNORM);
    AddConstant('DXGI_FORMAT_R9G9B9E5_SHAREDEXP',DXGI_FORMAT_R9G9B9E5_SHAREDEXP);
    AddConstant('DXGI_FORMAT_R8G8_B8G8_UNORM',DXGI_FORMAT_R8G8_B8G8_UNORM);
    AddConstant('DXGI_FORMAT_G8R8_G8B8_UNORM',DXGI_FORMAT_G8R8_G8B8_UNORM);
    AddConstant('DXGI_FORMAT_BC1_TYPELESS',DXGI_FORMAT_BC1_TYPELESS);
    AddConstant('DXGI_FORMAT_BC1_UNORM',DXGI_FORMAT_BC1_UNORM);
    AddConstant('DXGI_FORMAT_BC1_UNORM_SRGB',DXGI_FORMAT_BC1_UNORM_SRGB);
    AddConstant('DXGI_FORMAT_BC2_TYPELESS',DXGI_FORMAT_BC2_TYPELESS);
    AddConstant('DXGI_FORMAT_BC2_UNORM',DXGI_FORMAT_BC2_UNORM);
    AddConstant('DXGI_FORMAT_BC2_UNORM_SRGB',DXGI_FORMAT_BC2_UNORM_SRGB);
    AddConstant('DXGI_FORMAT_BC3_TYPELESS',DXGI_FORMAT_BC3_TYPELESS);
    AddConstant('DXGI_FORMAT_BC3_UNORM',DXGI_FORMAT_BC3_UNORM);
    AddConstant('DXGI_FORMAT_BC3_UNORM_SRGB',DXGI_FORMAT_BC3_UNORM_SRGB);
    AddConstant('DXGI_FORMAT_BC4_TYPELESS',DXGI_FORMAT_BC4_TYPELESS);
    AddConstant('DXGI_FORMAT_BC4_UNORM',DXGI_FORMAT_BC4_UNORM);
    AddConstant('DXGI_FORMAT_BC4_SNORM',DXGI_FORMAT_BC4_SNORM);
    AddConstant('DXGI_FORMAT_BC5_TYPELESS',DXGI_FORMAT_BC5_TYPELESS);
    AddConstant('DXGI_FORMAT_BC5_UNORM',DXGI_FORMAT_BC5_UNORM);
    AddConstant('DXGI_FORMAT_BC5_SNORM',DXGI_FORMAT_BC5_SNORM);
    AddConstant('DXGI_FORMAT_B5G6R5_UNORM',DXGI_FORMAT_B5G6R5_UNORM);
    AddConstant('DXGI_FORMAT_B5G5R5A1_UNORM',DXGI_FORMAT_B5G5R5A1_UNORM);
    AddConstant('DXGI_FORMAT_B8G8R8A8_UNORM',DXGI_FORMAT_B8G8R8A8_UNORM);
    AddConstant('DXGI_FORMAT_B8G8R8X8_UNORM',DXGI_FORMAT_B8G8R8X8_UNORM);
    AddConstant('DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM',DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM);
    AddConstant('DXGI_FORMAT_B8G8R8A8_TYPELESS',DXGI_FORMAT_B8G8R8A8_TYPELESS);
    AddConstant('DXGI_FORMAT_B8G8R8A8_UNORM_SRGB',DXGI_FORMAT_B8G8R8A8_UNORM_SRGB);
    AddConstant('DXGI_FORMAT_B8G8R8X8_TYPELESS',DXGI_FORMAT_B8G8R8X8_TYPELESS);
    AddConstant('DXGI_FORMAT_B8G8R8X8_UNORM_SRGB',DXGI_FORMAT_B8G8R8X8_UNORM_SRGB);
    AddConstant('DXGI_FORMAT_BC6H_TYPELESS',DXGI_FORMAT_BC6H_TYPELESS);
    AddConstant('DXGI_FORMAT_BC6H_UF16',DXGI_FORMAT_BC6H_UF16);
    AddConstant('DXGI_FORMAT_BC6H_SF16',DXGI_FORMAT_BC6H_SF16);
    AddConstant('DXGI_FORMAT_BC7_TYPELESS',DXGI_FORMAT_BC7_TYPELESS);
    AddConstant('DXGI_FORMAT_BC7_UNORM',DXGI_FORMAT_BC7_UNORM);
    AddConstant('DXGI_FORMAT_BC7_UNORM_SRGB',DXGI_FORMAT_BC7_UNORM_SRGB);
    AddConstant('DXGI_FORMAT_FORCE_UINT',DXGI_FORMAT_FORCE_UINT);
  end;
end;

class function TatDxgiFormatLibrary.LibraryName: string;
begin
  result := 'DxgiFormat';
end;

initialization
  RegisterScripterLibrary(TatDxgiFormatLibrary, True);

{$WARNINGS ON}

end.
