program exkeygn;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils,System.Hash;

var email,licenza:string;
var md5:THashMD5;

begin
 try
md5:=THashMD5.Create;
write('Inserisci la tua email: ');
read(email);
email:=email.ToLower;
licenza:=md5.GetHashString(email);

licenza:=licenza.ToUpper;
licenza:=licenza.Replace('0', 'C');
licenza:=licenza.Replace('O', 'K');
licenza:=licenza.Replace('I', '3');
licenza:=licenza.Replace('1', '7');
licenza:=licenza.Replace('L', 'T');
licenza:=licenza.Replace('S', 'W');
licenza:=licenza.Replace('B', 'V');
licenza:=licenza.Replace('8', '4');
licenza:=licenza.Replace('Z', 'X');
write('Licenza: '+(licenza.Substring(0,15)));
readln;
  except
    on E: Exception do
      Writeln(E.ClassName, ': ', E.Message);
  end;
end.
