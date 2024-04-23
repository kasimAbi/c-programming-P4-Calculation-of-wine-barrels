#define _CRT_SECURE_NO_WARNINGS // Fehlermeldung für scanf umgehen
// Bibliotheken einfügen
#include <stdio.h>
#include <math.h>
// Definitionen

int main(void){
	// Die Werte die man eingeben muss initialisiert:
	char name_des_weines[21] = { 0 };
	int artikelnummer = 0, anzahl__der_liefernden_weinflaschen = 0;
	float listenpreis_pro_flasche_ohne_mwst = 0.0 , versandkosten_inc_mwst = 0.0;

	int beenden = 1;
	// Die Werte die berechnet werden müssen, werden hier Initialisiert
	float reduzierter_preis_für_weinflaschen = 0.0, gesamtkosten_ohne_mwst = 0.0, gesamtkosten_mit_mwst = 0.0, preis_alle_flaschen = 0.0, mwst = 0.0;

	while (beenden != 0) {		// Führt nur die unten stehenden Befehle aus wenn die Variable beenden den Wert ungleich 0 hat
		printf("Geben sie den Namen von dem Wein:\t");		// Textausgabe
		scanf("%s", &name_des_weines[0]);		// Mit Leerzeichen funktioniert das Programm nicht. Ich weiß nicht warum // Texteingabe 
		fflush(stdin);		// Tastaturpuffer wird geleert

		printf("Geben sie die die Artikelnummer an:\t");	
		scanf("%i", &artikelnummer);	// Zahleingabe
		fflush(stdin);

		if (artikelnummer >= 0) {	// Führt nur aus wenn die Bedingung passt
			printf("Geben sie die Anzahl der zu liefernden Flaschen ein:\t");
			scanf("%i", &anzahl__der_liefernden_weinflaschen);
			fflush(stdin);

			if (anzahl__der_liefernden_weinflaschen >= 0) {
				printf("Geben sie die Kosten fuer eine Weinflasche (ohne MWST) ein:\t");
				scanf("%f", &listenpreis_pro_flasche_ohne_mwst);
				fflush(stdin);
				if (listenpreis_pro_flasche_ohne_mwst >= 0) {
					if (anzahl__der_liefernden_weinflaschen < 5)
					{
						reduzierter_preis_für_weinflaschen = listenpreis_pro_flasche_ohne_mwst * anzahl__der_liefernden_weinflaschen; // Ist eine Rechnung
					}

					if (anzahl__der_liefernden_weinflaschen >= 5 && anzahl__der_liefernden_weinflaschen <= 10)
					{
						reduzierter_preis_für_weinflaschen = (listenpreis_pro_flasche_ohne_mwst * anzahl__der_liefernden_weinflaschen) * 0.96;
					}

					if (anzahl__der_liefernden_weinflaschen >= 11 && anzahl__der_liefernden_weinflaschen <= 20)
					{
						reduzierter_preis_für_weinflaschen = (listenpreis_pro_flasche_ohne_mwst * anzahl__der_liefernden_weinflaschen) * 0.93;
					}

					if (anzahl__der_liefernden_weinflaschen > 20)
					{
						reduzierter_preis_für_weinflaschen = (listenpreis_pro_flasche_ohne_mwst * anzahl__der_liefernden_weinflaschen) * 0.9;
					}
				}
				else {		// Führt aus wenn die If- Bedingung zu der Else- Schleife nicht passt
					printf("Die Kosten fuer diie Weinflasche ist ungueltig: %.2f", listenpreis_pro_flasche_ohne_mwst);
					getchar();
					getchar();		// Hält das Programm vom direktem beenden auf
					beenden = 0;	// Ist eine end- Bedingung für die while- Schleife
				}
			}

			else {
				printf("Das Programm wird nun beenden wegen Falscher Wert fuer die Anzahl der zu liefernden Weinflaschen: %i", anzahl__der_liefernden_weinflaschen);
				beenden = 0;
				getchar();
				getchar();
			}
		}

		else {
			printf("Das Programm wird nun beenden wegen Falscher Wert fuer Artikelnummer: %i", artikelnummer);
			beenden = 0;
			getchar();
			getchar();
		}
		printf("Geben sie die Versandkosten (mit inclusive MehrWertSteuer) ein:\t");
		scanf("%f", &versandkosten_inc_mwst);
		fflush(stdin);
		
		if (versandkosten_inc_mwst >= 0) {
			// Gesamtkosten ohne MWST wird berechnet
			gesamtkosten_ohne_mwst = versandkosten_inc_mwst / 119 * 100 + reduzierter_preis_für_weinflaschen;

			// Der Preis fuer alle Flaschen wird berechnet
			preis_alle_flaschen = reduzierter_preis_für_weinflaschen;

			// Die MehrWertSteuer werden berechnet
			mwst = reduzierter_preis_für_weinflaschen / 100 * 19 + versandkosten_inc_mwst / 119 * 19;

			// Gesamtkosten mit MWST wird berechnet
			gesamtkosten_mit_mwst = gesamtkosten_ohne_mwst + mwst;

			// Rechnung fuer mit Rabatt pro Flasche
			reduzierter_preis_für_weinflaschen = reduzierter_preis_für_weinflaschen / anzahl__der_liefernden_weinflaschen;	
		}

		else {
			printf("Die Versandkosten haben einen ungueltigen Wert: %.2f", versandkosten_inc_mwst);
			getchar();
			getchar();
			beenden = 0;
		}

		printf("\nDer Name des Weines lautet \"%s\"\n", name_des_weines);		// Sind Textausgaben mit den entsprechenden Werten
		printf("Die Artikelnummer lautet \"%i\"\n", artikelnummer);
		printf("Der Preis fuer eine Flasche betraegt normalerweise (ohne MWST):\t%.2f Euro\n", listenpreis_pro_flasche_ohne_mwst);
		printf("Preis fuer Versandkosten mit MWST:\t%.2f\n\n", versandkosten_inc_mwst);
		versandkosten_inc_mwst = versandkosten_inc_mwst / 119 * 100;
		printf("Preis fuer Versandkosten ohne mwst:\t%.2f\n", versandkosten_inc_mwst);
		printf("Preis fuer eine Flasche betraegt in diesem Fall (ohne MWST):\t%.2f Euro\n", reduzierter_preis_für_weinflaschen);
		printf("Der Preis fuer alle Flaschen betraegt:\t%.2f Euro\n", preis_alle_flaschen);
		printf("Die Gesamtkosten ohne MWST betragen:\t%.2f Euro\n", gesamtkosten_ohne_mwst);
		printf("Die MWST betraegt:\t%.2f Euro\n\n", mwst);
		printf("Die Gesamtkosten einschliesslich MWST betragen %.2f Euro\n\n\n", gesamtkosten_mit_mwst);
		getchar();
	}
	return(1);		// Rückgabewert
}	// Ende