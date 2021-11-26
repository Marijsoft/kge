#-------------------------------------------------------------------------------
# Name:        keygen
# Purpose:
#
# Author:      aloel
#
# Created:     25/11/2021
# Copyright:   (c) aloel 2021
# Licence:     <your licence>
#-------------------------------------------------------------------------------
import sys
import codecs
import hashlib
from os import system
system("title Excel2MySQL Keygen by Marijuana")

def generalicenza(email):
    email = email.lower().encode('utf-8')
    md5 = hashlib.md5()
    md5.update(email)
    licenza = md5.hexdigest().upper()
    licenza = codecs.encode(licenza, 'rot-13')
    licenza = licenza.replace('0', 'C').replace('O', 'K').replace('I', '3').replace('1', '7').replace('L', 'T').replace('S', 'W').replace('B', 'V').replace('8', '4').replace('Z', 'X')
    print("\nLicenza: " + licenza[0:15])

def main():
    print("n\Excel2MySql keygen") 
    email = input("Inserisci il tuo indirizzo email:")
    generalicenza (email)
 #   input() #per generare un altro seriale

if __name__ == "__main__":
    main()
