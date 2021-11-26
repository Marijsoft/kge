unit excelmysqlkg;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants,
  System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, System.Hash, Vcl.StdCtrls, Vcl.Mask,
  Vcl.ExtCtrls, Vcl.Clipbrd;

type
  TForm1 = class(TForm)
    Button1: TButton;
    LabeledEdit1: TLabeledEdit;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}
{$REGION 'funzione rot13'}
function Rot13(c: AnsiChar): AnsiChar;
begin
  Result := c;
  if (c >= 'a') and (c <= 'm') or (c >= 'A') and (c <= 'M') then
    Result := AnsiChar(ord(c) + 13)
  else if (c >= 'n') and (c <= 'z') or (c >= 'N') and (c <= 'Z') then
    Result := AnsiChar(ord(c) - 13);
end;

function Rot13Enc(s: ansistring): ansistring;
begin
  SetLength(Result, length(s));
  for var i := 1 to length(s) do
    Result[i] := Rot13(s[i]);
end;
{$ENDREGION}

{$REGION 'Genera chiave'}
procedure TForm1.Button1Click(Sender: TObject);
var
  md5: THashMD5;
  licenza: string;
begin
  md5 := THashMD5.Create;
  try
    licenza := md5.GetHashString(LabeledEdit1.Text);
    licenza := licenza.ToUpper;
    licenza := Rot13Enc(licenza);
    licenza := licenza.Replace('0', 'C').Replace('O', 'K').Replace('I', '3')
      .Replace('L', 'T').Replace('S', 'W').Replace('B', 'V').Replace('8', '4')
      .Replace('Z', 'X').Replace('1', '7');
  finally
    Label1.Caption := 'Licenza: ' + licenza.Substring(0, 15);
    Clipboard.AsText := licenza.Substring(0, 15);
  end;
end;
{$ENDREGION}

end.
