#include "license.h"
#include "guild.h"
#include "person.h"
using namespace std;

int main() {
    // 1. Lizenzüberprüfung
    License license("City watch", 5);
    cout << "License Info: " << license << endl;

    // 2. Gildenüberprüfung
    shared_ptr<Person> person1 = make_shared<Person>("Carrot Ironfoundersson", 100);
    shared_ptr<Person> person2 = make_shared<Person>("Samuel Vimes", 150);

    Guild guild("City watch", 6, 5, {person1, person2});
    cout << "Guild Info: " << guild << endl;

    // Lizenzvergabe
    guild.grant_license("Carrot Ironfoundersson");
    guild.grant_license("Samuel Vimes");

    // Angebot einer Aufgabe
    guild.offer_job(person1);

    // 3. Personüberprüfung
    cout << "Person Info: " << *person1 << endl;

    // 3.1 Workerüberprüfung
    Worker worker("Fred Colon", 50);
    worker.work(10);
    cout << "Worker Info: " << worker << endl;

    // 3.2 Superworkerüberprüfung
    Superworker superworker(3, "Nobby Nobbs", 70);
    superworker.work(15);
    cout << "Superworker Info: " << superworker << endl;


    // Abrufen der Person mit den höchsten Einnahmen
    auto topEarner = guild.getTopEarner();
    if (topEarner.lock()) {
        cout << "Top Earner: " << topEarner.lock()->get_name() << endl;
    } else {
        cout << "Kein Top Earner gefunden." << endl;
    }

    return 0;
}
