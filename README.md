# smart_ptr
Smart Pointer Projekt - Implementierungsziele und C++-Konzepte
1. Lizenz
Implementierungsziele:

    Zweck: Darstellung einer Lizenz, ausgestellt von einer Gilde für die Durchführung von Aufgaben.
    Funktionalität:
        Verfolgung des Gildennamens, des Gehalts für eine Aufgabe und der Anzahl abgeschlossener Aufgaben.
        Bereitstellung von Methoden zum Zugriff und zur Manipulation dieser Attribute.
        Ermöglichen des Drucks von Lizenzinformationen.

C++-Konzepte:

    Konstruktoren: Parameterisierter Konstruktor zur Initialisierung der Lizenzattribute.
    Methoden: Getter-Methoden zum Abrufen von Informationen; valid und use zum Überprüfen und Aktualisieren des Lizenzstatus.
    Operatorüberladung: Überladen von << für benutzerdefinierte Ausgabe.

2. Gilde
Implementierungsziele:

    Zweck: Darstellung einer Gilde mit Mitgliedern, Lizenzen und Jobangeboten.
    Funktionalität:
        Verwalten von Gildenmitgliedern, Lizenzen und Jobangeboten.
        Umgang mit Lizenzvergaben, Mitgliedschaften und -entfernungen.
        Bereitstellung von Informationen über die Gilde und ihre Mitglieder.

C++-Konzepte:

    Konstruktoren: Parameterisierter Konstruktor mit optionaler Mitgliedsinitialisierung.
    Datenstrukturen: Verwenden einer map zur Verwaltung von Gildenmitgliedern.
    Ausnahmebehandlung: Auslösen von runtime_error für Ausnahmefälle.
    Operatorüberladung: Überladen von << für benutzerdefinierte Ausgabe.

3. Person
Implementierungsziele:

    Zweck: Darstellung einer Einzelperson mit Vermögen, Lizenzen und Arbeitsfähigkeiten.
    Funktionalität:
        Verwalten von persönlichem Vermögen, Lizenzen und Durchführung von Arbeiten.
        Umgang mit Lizenzübertragungen, Zahlungen und arbeitsbezogenen Operationen.
        Bereitstellung von Informationen über die Person.

C++-Konzepte:

    Konstruktoren: Parameterisierter Konstruktor zur Initialisierung persönlicher Attribute.
    Vererbung: Ableitung von Worker und Superworker von der Basisklasse Person.
    Polymorphismus: Definition virtueller Methoden und reiner virtueller Methoden für unterschiedliche Verhaltensweisen.
    Operatorüberladung: Überladen von << für benutzerdefinierte Ausgabe.

3.1 Worker
Implementierungsziele:

    Zweck: Darstellung einer arbeitenden Person ohne zusätzliche Gebühren für Aufgaben.
    Funktionalität:
        Durchführung von Arbeiten und Erhöhung des Vermögens entsprechend.

C++-Konzepte:

    Vererbung: Abgeleitet von der Klasse Person.
    Polymorphismus: Implementierung einer spezialisierten work-Methode.

3.2 Superworker
Implementierungsziele:

    Zweck: Darstellung einer Person, die eine Gebühr für jede durchgeführte Aufgabe erhebt.
    Funktionalität:
        Durchführung von Arbeiten und Erhöhung des Vermögens mit einer zusätzlichen Gebühr.

C++-Konzepte:

    Vererbung: Abgeleitet von der Klasse Person.
    Polymorphismus: Implementierung einer spezialisierten work-Methode.
