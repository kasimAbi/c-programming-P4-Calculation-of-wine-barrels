/******************************************************/
/* Autor: Kasim Mermer                                */
/* Datum: 23.10.2016                                  */
/* Projekt: P4A1                                      */
/* Beschreibung: Berechnung von Weinf�ssern			  */
/******************************************************/

#define _CRT_SECURE_NO_WARNINGS		// Fehlermeldung wegen scanf umgehen
#include <stdio.h>			// Bibliotheken hinzuf�gen
#include <math.h>
#define moselwein 0.916		// Definitionen aus dem Internet
#define pi 3.141592

int main(void) {
	float unten_oben_durchmesser = 0.0, mitte_durchmesser = 0.0, h�he = 0.0;		// Initialisierung
	int beenden = 1;

	// Initialisierung der zur berechnenden Werte
	float grundfl�che = 0.0, deckfl�che = 0.0, mantelfl�che = 0.0, oberfl�che = 0.0, volumen = 0.0, gewicht_inhalt_wenn_fass_mit_moselwein_gef�llt = 0.0;
	float radius_von_grundfl�che = 0.0, mantellinie = 0.0, radius_deckfl�che = 0.0, h�he_halber_fass;

	while (beenden != 0) { // F�hrt die Folgenden Befehle solange aus, solange die Variable "beenden" nicht den Wert 0 hat.
		printf("ALLE WERTE IN \"cm\" EINGEBEN\nGeben sie den oberen bzw. unteren durchmesser ein:\t");	// Textausgabe
		scanf("%f", &unten_oben_durchmesser);		// Zahl eingabe
		fflush(stdin);		// tastaturpuffer l�schen
		radius_deckfl�che = unten_oben_durchmesser / 2.0;		// Den oberen bzw. unteren Radius berechnen

		printf("Nun geben sie den mittleren durchmesser ein:\t\t");
		scanf("%f", &mitte_durchmesser);
		fflush(stdin);
		radius_von_grundfl�che = mitte_durchmesser / 2.0;		// Den mittleren Radius berechnen

		printf("und jetzt wird der Wert fuer die hoehe benoetigt:\t");
		scanf("%f", &h�he);
		fflush(stdin);
		h�he_halber_fass = h�he / 2.0;		// H�he f�r den Halben Fass berechnen weil ich die Formeln unten so einfach rechnen kann
		printf("\n\n");		// zwei Zeilenspr�nge

		if (mitte_durchmesser > unten_oben_durchmesser && unten_oben_durchmesser > 0 && h�he > 0) {		// F�hrt nur die unten genannten Befehle aus wenn der Fall auch zutrifft
			// Berechnung der Grundflaeche:
			grundfl�che = pi * radius_von_grundfl�che * radius_von_grundfl�che;		
			
			// Berechnung der Deckflaeche:
			deckfl�che = pi * radius_deckfl�che * radius_deckfl�che;
			
			// F�r die Mantelfl�che wird auch die Mantellinie ben�tigt darum muss man erst die Mantellinie ausrechnen:
			mantellinie = sqrt(pow(radius_von_grundfl�che - radius_deckfl�che,2) + pow(h�he_halber_fass,2));
			mantellinie = mantellinie * 2.0;

			// Anschlie�end wird die Mantelf�che berechnet:
			mantelfl�che = (radius_von_grundfl�che + radius_deckfl�che) * pi * mantellinie;

			// Berechnung der Oberfl�che:
			// oberfl�che = pi * (pow(radius_deckfl�che,2) + pow(radius_von_grundfl�che,2) + mantellinie * (radius_deckfl�che + radius_von_grundfl�che));
			oberfl�che = mantelfl�che + 2.0*deckfl�che;

			// Berechnung des Volumens:
			volumen = ((h�he_halber_fass * pi / 3.0) * (pow(radius_von_grundfl�che,2) + radius_von_grundfl�che * radius_deckfl�che + pow(radius_deckfl�che,2)));
			volumen = volumen * 2.0;

			// Ausgabe von den Werten
			printf("Die Grundflaeche ist %.2f cm^2 gross.\n", grundfl�che);
			printf("Die Deckflaeche ist %.2f cm^2 gross.\n", deckfl�che);
			printf("Die groesse von der mantelflaeche lautet: %.2f cm^2.\n", mantelfl�che);
			printf("Die Oberflaeche ist %.2f cm^2 gross.\n", oberfl�che);

			// Berechnung von dem Gewicht des Inhaltes, wenn das Fass mit Moselwein gef�llt ist und die Ausgabe:
			gewicht_inhalt_wenn_fass_mit_moselwein_gef�llt = moselwein * volumen;
			printf("Das Volumen ist %.2f cm^3 gross.\n", volumen);
			printf("Das Gewicht des Inhaltes, mit Moselwein gefuellt betraegt: %.2f gramm.\n\n", gewicht_inhalt_wenn_fass_mit_moselwein_gef�llt);
			
			printf("wenn sie das programm beenden moechten geben sie eine \"0\" ein:\t");
			scanf("%i", &beenden);		// Wert f�r die Variable beenden zuweisen. Falls der Wert 0 lautet, wird das Programm beenden bzw. die while- Schleife wird verlassen.
			fflush(stdin);
			printf("\n\n\n");
		}
		else {		// F�hrt nur aus, wenn die If- Bedingung nciht erf�llt worden ist.
			printf("Fehler der gegebenen Werte!\n");
			printf("Werte werden ausgegeben.\n- der untere bzw. obere durchmesser betraegt %.2f cm\n", unten_oben_durchmesser);
			printf("- der mittlere durchmesser betraegt %.2f\n- die hoehe betraegt %.2f cm\n\n", mitte_durchmesser, h�he);
		}
	}
	return(1);		// R�ckgabewert
}	// Ende vom Programm

// Die Formeln habe ich aus der Seite: https://de.m.wikipedia.org/wiki/Kegelstumpf


// mantelfl�che = 0.217m^2