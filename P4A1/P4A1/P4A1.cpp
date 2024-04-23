/******************************************************/
/* Autor: Kasim Mermer                                */
/* Datum: 23.10.2016                                  */
/* Projekt: P4A1                                      */
/* Beschreibung: Berechnung von Weinfässern			  */
/******************************************************/

#define _CRT_SECURE_NO_WARNINGS		// Fehlermeldung wegen scanf umgehen
#include <stdio.h>			// Bibliotheken hinzufügen
#include <math.h>
#define moselwein 0.916		// Definitionen aus dem Internet
#define pi 3.141592

int main(void) {
	float unten_oben_durchmesser = 0.0, mitte_durchmesser = 0.0, höhe = 0.0;		// Initialisierung
	int beenden = 1;

	// Initialisierung der zur berechnenden Werte
	float grundfläche = 0.0, deckfläche = 0.0, mantelfläche = 0.0, oberfläche = 0.0, volumen = 0.0, gewicht_inhalt_wenn_fass_mit_moselwein_gefüllt = 0.0;
	float radius_von_grundfläche = 0.0, mantellinie = 0.0, radius_deckfläche = 0.0, höhe_halber_fass;

	while (beenden != 0) { // Führt die Folgenden Befehle solange aus, solange die Variable "beenden" nicht den Wert 0 hat.
		printf("ALLE WERTE IN \"cm\" EINGEBEN\nGeben sie den oberen bzw. unteren durchmesser ein:\t");	// Textausgabe
		scanf("%f", &unten_oben_durchmesser);		// Zahl eingabe
		fflush(stdin);		// tastaturpuffer löschen
		radius_deckfläche = unten_oben_durchmesser / 2.0;		// Den oberen bzw. unteren Radius berechnen

		printf("Nun geben sie den mittleren durchmesser ein:\t\t");
		scanf("%f", &mitte_durchmesser);
		fflush(stdin);
		radius_von_grundfläche = mitte_durchmesser / 2.0;		// Den mittleren Radius berechnen

		printf("und jetzt wird der Wert fuer die hoehe benoetigt:\t");
		scanf("%f", &höhe);
		fflush(stdin);
		höhe_halber_fass = höhe / 2.0;		// Höhe für den Halben Fass berechnen weil ich die Formeln unten so einfach rechnen kann
		printf("\n\n");		// zwei Zeilensprünge

		if (mitte_durchmesser > unten_oben_durchmesser && unten_oben_durchmesser > 0 && höhe > 0) {		// Führt nur die unten genannten Befehle aus wenn der Fall auch zutrifft
			// Berechnung der Grundflaeche:
			grundfläche = pi * radius_von_grundfläche * radius_von_grundfläche;		
			
			// Berechnung der Deckflaeche:
			deckfläche = pi * radius_deckfläche * radius_deckfläche;
			
			// Für die Mantelfläche wird auch die Mantellinie benötigt darum muss man erst die Mantellinie ausrechnen:
			mantellinie = sqrt(pow(radius_von_grundfläche - radius_deckfläche,2) + pow(höhe_halber_fass,2));
			mantellinie = mantellinie * 2.0;

			// Anschließend wird die Mantelfäche berechnet:
			mantelfläche = (radius_von_grundfläche + radius_deckfläche) * pi * mantellinie;

			// Berechnung der Oberfläche:
			// oberfläche = pi * (pow(radius_deckfläche,2) + pow(radius_von_grundfläche,2) + mantellinie * (radius_deckfläche + radius_von_grundfläche));
			oberfläche = mantelfläche + 2.0*deckfläche;

			// Berechnung des Volumens:
			volumen = ((höhe_halber_fass * pi / 3.0) * (pow(radius_von_grundfläche,2) + radius_von_grundfläche * radius_deckfläche + pow(radius_deckfläche,2)));
			volumen = volumen * 2.0;

			// Ausgabe von den Werten
			printf("Die Grundflaeche ist %.2f cm^2 gross.\n", grundfläche);
			printf("Die Deckflaeche ist %.2f cm^2 gross.\n", deckfläche);
			printf("Die groesse von der mantelflaeche lautet: %.2f cm^2.\n", mantelfläche);
			printf("Die Oberflaeche ist %.2f cm^2 gross.\n", oberfläche);

			// Berechnung von dem Gewicht des Inhaltes, wenn das Fass mit Moselwein gefüllt ist und die Ausgabe:
			gewicht_inhalt_wenn_fass_mit_moselwein_gefüllt = moselwein * volumen;
			printf("Das Volumen ist %.2f cm^3 gross.\n", volumen);
			printf("Das Gewicht des Inhaltes, mit Moselwein gefuellt betraegt: %.2f gramm.\n\n", gewicht_inhalt_wenn_fass_mit_moselwein_gefüllt);
			
			printf("wenn sie das programm beenden moechten geben sie eine \"0\" ein:\t");
			scanf("%i", &beenden);		// Wert für die Variable beenden zuweisen. Falls der Wert 0 lautet, wird das Programm beenden bzw. die while- Schleife wird verlassen.
			fflush(stdin);
			printf("\n\n\n");
		}
		else {		// Führt nur aus, wenn die If- Bedingung nciht erfüllt worden ist.
			printf("Fehler der gegebenen Werte!\n");
			printf("Werte werden ausgegeben.\n- der untere bzw. obere durchmesser betraegt %.2f cm\n", unten_oben_durchmesser);
			printf("- der mittlere durchmesser betraegt %.2f\n- die hoehe betraegt %.2f cm\n\n", mitte_durchmesser, höhe);
		}
	}
	return(1);		// Rückgabewert
}	// Ende vom Programm

// Die Formeln habe ich aus der Seite: https://de.m.wikipedia.org/wiki/Kegelstumpf


// mantelfläche = 0.217m^2