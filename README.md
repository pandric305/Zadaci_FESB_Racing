Ovdje se nalaze rješenja uvodnih zadataka za FESB Racing.

1. Zadatak:
   Koristeći C/C++ isprogramirati Arduino Mikrokontroler tako da jednu ledicu pali u intervalu od dvije sekunde, a drugu u intervalu od tri sekunde.
   Ledice neka budu upaljene pola sekunde prije nego se opet ugase. Kod možete testirati koristeći https://wokwi.com/ stranicu gdje možete simulirati izvođenje kod na
   Arduino mikrokontroleru.

2. Zadatak:
   a) Koristeći C ili C++ programski jezik napisati funkciju koja kao argument uzima string s heksadecimalnim znamenkama, a vraća decimalnu vrijednost tog broja. Kod testirati
      unutar terminala na vašem računalu.
   b) Napraviti prezentaciju 6-10 slajdova o SPI komunikacijskom protokolu te opisati uloge SCK, SI, SO i CS pinova.

3. Zadatak:
   a) Istražiti što je CAN protokol, u njegovom kontekstu objasniti pojmove arbitraža i kolizija. Navesti najčešće vrijednosti bitrate-a koji se koriste u CAN mreži. Objasniti
      ulogu CAN mreže u automobilu. Može li automobil imati više CAN mreža? Ako može, navesti zašto automobili u praksi imaju više odvojenih CAN mreža. Objasniti uloge
      svih polja okvira CAN poruke.
   b) Ukratko usporediti SPI i CAN protokol (Bitrate, broj žica, domet(max. Udaljenost dva čvora u mreži), svrha…). Navedite neki svoj primjer gdje bi ste na automobilu
      koristili CAN, a gdje SPI protokol za komunikaciju između računala.

4. Zadatak:
   a) Objasniti uloge pinova MCP2515 chipa (INT, SI, SO, CS, GND, VCC, CAN H, CAN L) i za što se koristiti chip.
   b) Pronaći shemu spajanja Arduino Uno pločice i MCP2515 chipa.
   c) Koristeći mcp_can library napisati kod za slanje CAN poruke (testirati će se u ugaraži).
   d) Napisati kod koji prima CAN poruke i ispisuje ID i DATA polje u konzoli (testirati će se u garaži).
