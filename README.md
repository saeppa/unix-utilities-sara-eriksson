# Projektityö 2 - UNIX Utilities 
CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
 
## Tekijät
- Sara Eriksson 
- Sami Salonen 

## Yhteenveto
Toteutimme OSTEP-projektien mukaiset neljä C-kielistä komentorivityökalua: **my-cat**, **my-grep**, **my-zip** ja **my-unzip**. 
Ohjelmat vastaavat tehtävänannon yksinkertaistettuja UNIX-työkaluja ja sisältävät määritellyt virheilmoitukset sekä exit-koodit. 
Kaikki ohjelmat kääntyvät parametreilla `-Wall -Werror`.


## Ohjelmat 

### my-cat
- Tulostaa tiedostojen sisällön stdoutiin. 
- Virhe: `my-cat: cannot open file` → exit 1.

### my-grep
- Hakee hakusanaa riveiltä (case-sensitive). 
- Tukee useita tiedostoja ja stdin-lukua (`getline()`). 
- Virheet: 
  - Ei argumentteja → `my-grep: searchterm [file ...]`, exit 1 
  - Ei voi avata tiedostoa → `my-grep: cannot open file`, exit 1

### my-zip
- RLE-pakkaus: 4 tavun `int32_t` + 1 tavun merkki. 
- Tulostaa binäärin stdoutiin. 
- Virhe: `my-zip: file1 [file2 ...]`, exit 1.
 
### my-unzip
- Purkaa yllä kuvatun RLE-muodon stdoutiin. 
- Virhe: `my-unzip: file1 [file2 ...]`, exit 1.

## Kääntäminen
```bash
gcc -o my-cat my-cat.c -Wall -Werror
gcc -o my-grep my-grep.c -Wall -Werror
gcc -o my-zip my-zip.c -Wall -Werror
gcc -o my-unzip my-unzip.c -Wall -Werror

## Lähteet
Remzi H. Arpaci-Dusseau & Andrea C. Arpaci-Dusseau – Operating Systems: Three Easy Pieces
OSTEP Project Repository (tehtävänanto)
Stevens & Rago – Advanced Programming in the UNIX Environment.
Linux man-sivut: fopen, fgets, getline, fread, fwrite
