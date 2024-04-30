// C++ program to implement Bus Reservation System 
#include <algorithm> 
#include <iostream> 
#include <limits> 
#include <string> 
#include <vector> 

using namespace std; 

// untility function to print line 
void printLine(int length, const char c) 
{ 
	for (int i = 0; i < length; i++) { 
		cout << c; 
	} 
	cout << endl; 
} 

// forward declartions 
class User; 
class Ticket; 
class Bus; 
class Route; 

// This class defines the route details and all the 
// functions associated with route. 
class Route { 
public: 
	Route(const string& name, const string& source, 
		const string& destination, int distance) 
		: name(name) 
		, source(source) 
		, destination(destination) 
		, distance(distance) 
	{ 
	} 

	string getName() const { return name; } 
	string getSource() const { return source; } 
	string getDestination() const { return destination; } 
	int getDistance() const { return distance; } 

private: 
	string name; 
	string source; 
	string destination; 
	int distance; 
}; 

// This class is used to store the ticked data and defines 
// the related functions 
class Bus { 
public: 
	Bus(const string& busNumber, const Route& route, 
		int totalSeats) 
		: busNumber(busNumber) 
		, route(route) 
		, totalSeats(totalSeats) 
	{ 
		seats.reserve(totalSeats); 
		for (int i = 1; i <= totalSeats; ++i) { 
			seats.push_back(false); 
		} 
	} 

	bool reserveSeat(int seatNumber) 
	{ 
		if (seatNumber >= 1 && seatNumber <= totalSeats 
			&& !seats[seatNumber - 1]) { 
			seats[seatNumber - 1] = true; 
			return true; 
		} 
		return false; 
	} 

	int getTotalSeats() const { return totalSeats; } 

	bool cancelSeat(int seatNumber) 
	{ 
		if (seatNumber >= 1 && seatNumber <= totalSeats 
			&& seats[seatNumber - 1]) { 
			seats[seatNumber - 1] = false; 
			return true; 
		} 
		return false; 
	} 

	void displayBusInfo() const
	{ 
		cout << "\n\t\t\tBus Number: " << busNumber << endl; 
		cout << "\t\tRoute: " << route.getName() << " ("
			<< route.getSource() << " to "
			<< route.getDestination() << ")\n"; 
		cout << "\t\t\tDistance: " << route.getDistance() 
			<< " km" << endl; 
		cout << "\t\t\tTotal Seats: " << totalSeats << endl; 
		cout << "\t\t----- Availabe Seat -----\n"; 
		bool flag = false; 
		for (int i = 0; i < totalSeats; i++) { 
			if (!seats[i]) { 
				cout << "\t\t" << i + 1; 
			} 
			else { 
				cout << "\t\tNA"; 
			} 
			if (!flag) { 
				cout << "\t"; 
				flag = true; 
			} 
			else { 
				cout << "\n"; 
				flag = false; 
			} 
		} 
		cout << endl; 
	} 

	void displayAvailableSeats() const
	{ 
		cout << "\t\t\tAvailable Seats on Bus " << busNumber 
			<< ":\n"; 
		for (int i = 0; i < totalSeats; ++i) { 
			if (seats[i]) { 
				cout << "\t\t\tSeat " << i + 1 
					<< ": Available\n"; 
			} 
		} 
	} 

	void displayBusStatus() const
	{ 
		int reservedSeats = 0; 
		for (int i = 0; i < totalSeats; ++i) { 
			if (seats[i]) { 
				reservedSeats++; 
			} 
		} 

		cout << "Bus Status for Bus " << busNumber << ":\n"; 
		cout << "Total Seats: " << totalSeats << "\n"; 
		cout << "Reserved Seats: " << reservedSeats << "\n"; 
		cout << "Available Seats: "
			<< totalSeats - reservedSeats << "\n"; 
	} 

	string getBusNumber() const { return busNumber; } 

	const Route& getRoute() const { return route; } 

private: 
	string busNumber; 
	Route route; 
	int totalSeats; 
	vector<bool> seats; 
}; 

// This class is used to store the ticked data and defines 
// the related functions 
class Ticket { 
public: 
	Ticket(const string& passengerName, int seatNumber, 
		Route& route, const Bus& bus) 
		: passengerName(passengerName) 
		, seatNumber(seatNumber) 
		, route(route) 
		, bus(bus) 
	{ 
	} 

	string getPassengerName() const
	{ 
		return passengerName; 
	} 
	int getSeatNumber() const { return seatNumber; } 
	const Route& getRoute() const { return route; } 
	const Bus& getBus() const { return bus; } 

private: 
	string passengerName; 
	int seatNumber; 
	Route route; 
	Bus bus; 
}; 

// This Class is for storing and accessing user data. 
class User { 
public: 
	User(const string& username, const string& password) 
		: username(username) 
		, password(password) 
	{ 
	} 

	string getUsername() const { return username; } 
	string getPassword() const { return password; } 
	void addTicket(Ticket& newTicket) 
	{ 
		tickets.push_back(newTicket); 
	} 

	void removeTicket(int index) 
	{ 
		vector<Ticket>::iterator i = tickets.begin(); 
		i = i + index - 1; 
		tickets.erase(i); 
	} 

	void printAllTickets() const
	{ 
		int i = 0; 
		for (i = 0; i < tickets.size(); i++) { 
			cout << "\n\t\t------ Ticket " << i + 1 
				<< " ------" << endl; 
			cout << "\t\t\tPassenger: "
				<< tickets[i].getPassengerName() << endl; 
			cout << "\t\tRoute: "
				<< tickets[i].getRoute().getName() << " ("
				<< tickets[i].getRoute().getSource() 
				<< " to "
				<< tickets[i].getRoute().getDestination() 
				<< ")\n"; 
			cout << "\t\t\tBus Number: "
				<< tickets[i].getBus().getBusNumber() 
				<< endl; 
			cout << "\t\t\tSeat Number: "
				<< tickets[i].getSeatNumber() << endl; 
		} 
	} 

	int numberOfTickets() const { return tickets.size(); } 

	Ticket& getTicket(int index) 
	{ 
		return tickets[index - 1]; 
	} 

private: 
	string username; 
	string password; 
	vector<Ticket> tickets; 
}; 

class BusReservationSystem { 
public: 
	BusReservationSystem() 
	{ 
		// Sample routes 
		routes.push_back( 
			Route("R001", "City A", "City B", 200)); 
		routes.push_back( 
			Route("R002", "City B", "City C", 150)); 
		routes.push_back( 
			Route("R003", "City C", "City D", 180)); 

		// Sample buses 
		buses.push_back(Bus("B001", routes[0], 20)); 
		buses.push_back(Bus("B002", routes[1], 15)); 
		buses.push_back(Bus("B003", routes[2], 18)); 
	} 

	void registerUser(const string& username, 
					const string& password) 
	{ 
		users.push_back(User(username, password)); 
		cout << "\n\t\tUser registered successfully. "
				"Please login to continue!\n"; 
	} 

	bool authenticateUser(const string& username, 
						const string& password) 
	{ 
		for (const User& user : users) { 
			string lowercaseUsername = user.getUsername(); 
			string lowercaseInputUsername = username; 
			transform(lowercaseUsername.begin(), 
					lowercaseUsername.end(), 
					lowercaseUsername.begin(), ::tolower); 
			transform(lowercaseInputUsername.begin(), 
					lowercaseInputUsername.end(), 
					lowercaseInputUsername.begin(), 
					::tolower); 

			if (lowercaseUsername == lowercaseInputUsername 
				&& user.getPassword() == password) { 
				return true; 
			} 
		} 
		return false; 
	} 

	User& findUser(string username) 
	{ 
		for (int i = 0; i < users.size(); i++) { 
			if (users[i].getUsername() == username) { 
				return users[i]; 
			} 
		} 
		return users[users.size() - 1]; 
	} 

	void displayRoutes() const
	{ 
		cout << "\n\t\t------ Available Routes ------\n"; 
		for (const Route& route : routes) { 
			cout << "\n\t\tRoute Name: " << route.getName() 
				<< " (" << route.getSource() << " to "
				<< route.getDestination() << ")\n"; 
			cout << "\t\t\tDistance: "
				<< route.getDistance() << " km" << endl; 
		} 
	} 

	void displayBuses() const
	{ 
		cout << "\t\t------ Available Buses ------\n"; 
		for (const Bus& bus : buses) { 
			bus.displayBusInfo(); 
			cout << endl; 
		} 
	} 

	void displayBusesForRoute(int selectedRoute) const
	{ 
		cout << "\t\t\tBuses available for Route "
			<< routes[selectedRoute - 1].getName() 
			<< ":\n"; 
		for (int i = 0; i < buses.size(); i++) { 
			if (buses[i].getRoute().getName() 
				== routes[selectedRoute - 1].getName()) { 
				buses[i].displayBusInfo(); 
				cout << endl; 
			} 
		} 
	} 

	void bookTicket(const string& username) 
	{ 
		int selectedRoute, selectedBus, selectedSeat; 

		displayRoutes(); 
		cout << "\n\t\tSelect a Route (Enter the Route "
				"Number): "; 
		string routeNumber; 
		cin >> routeNumber; 

		bool validRoute = false; 
		for (int i = 0; i < routes.size(); i++) { 
			if (routeNumber == routes[i].getName()) { 
				selectedRoute = i + 1; 
				validRoute = true; 
				break; 
			} 
		} 

		if (!validRoute) { 
			cout << "\n\tInvalid route number. Please "
					"enter a valid route number.\n"; 
			return; // Return to the main menu 
		} 

		// Consume the newline character 
		cin.ignore( 
			std::numeric_limits<std::streamsize>::max(), 
			'\n'); 

		// Display buses for the selected route 
		displayBusesForRoute(selectedRoute); 

		cout << "\n\t\tSelect a Bus (Enter the Bus "
				"Number): "; 
		string busNumber; 
		cin >> busNumber; 

		validRoute = false; 
		for (int i = 0; i < buses.size(); i++) { 
			if (busNumber == buses[i].getBusNumber() 
				&& buses[i].getRoute().getName() 
					== routes[selectedRoute - 1] 
							.getName()) { 
				selectedBus = i + 1; 
				validRoute = true; 
				break; 
			} 
		} 

		if (!validRoute) { 
			cout << "\n\tInvalid bus number. Please enter "
					"a valid bus number for the selected "
					"route.\n"; 
			return; // Return to the main menu 
		} 

		// Consume the newline character 
		cin.ignore( 
			std::numeric_limits<std::streamsize>::max(), 
			'\n'); 

		cout << "\n\t\tEnter the seat number you want to "
				"book: "; 
		cin >> selectedSeat; 

		if (cin.fail() || selectedSeat < 1 
			|| selectedSeat > buses[selectedBus - 1] 
								.getTotalSeats()) { 
			cout << "\n\tInvalid seat number. Please enter "
					"a valid seat number for the selected "
					"bus.\n"; 
			return; // Return to the main menu 
		} 

		if (buses[selectedBus - 1].reserveSeat( 
				selectedSeat)) { 
			Ticket ticket(username, selectedSeat, 
						routes[selectedRoute - 1], 
						buses[selectedBus - 1]); 
			User& user = findUser(username); 
			user.addTicket(ticket); 
			cout << "\n\t\t\tTicket booked successfully!\n"; 
			cout << "\t\t\tPassenger: "
				<< ticket.getPassengerName() << "\n"; 
			cout << "\t\t\tBus Number: "
				<< buses[selectedBus - 1].getBusNumber() 
				<< "\n"; 
			cout << "\t\t\tRoute: "
				<< ticket.getRoute().getName() << " ("
				<< ticket.getRoute().getSource() << " to "
				<< ticket.getRoute().getDestination() 
				<< ")\n"; 
			cout << "\t\t\tSeat Number: "
				<< ticket.getSeatNumber() << "\n"; 
			buses[selectedBus - 1].displayBusStatus(); 
		} 
		else { 
			cout << "\n\tSeat booking failed. The seat is "
					"already reserved or does not exist.\n"; 
		} 
	} 

	void cancelTicket(const string& username) 
	{ 
		int ticketDel = -1; 
		User& user = findUser(username); 
		if (user.numberOfTickets() <= 0) { 
			cout << "\n\t\t\nNo Tickets Booked!\n"; 
			return; 
		} 
		user.printAllTickets(); 

		cout << "\t\t\nSelect the ticked to be "
				"cancelled... "; 
		cin >> ticketDel; 

		// Consume the newline character 
		cin.ignore( 
			std::numeric_limits<std::streamsize>::max(), 
			'\n'); 

		if (cin.fail() 
			|| ticketDel > user.numberOfTickets()) { 
			cout << "\tInvalid Ticked Selected! Please "
					"select a valid ticket\n"; 
			return; 
		} 
		else { 
			cout << "\t\t\tTicket canceled successfully.\n"; 
			Ticket ticket = user.getTicket(ticketDel); 
			Bus bus = ticket.getBus(); 
			for (int i = 0; i < buses.size(); i++) { 
				if (buses[i].getBusNumber() 
					== bus.getBusNumber()) { 
					buses[i].cancelSeat( 
						ticket.getSeatNumber()); 
				} 
			} 
			user.removeTicket(ticketDel); 
		} 
	} 

	void run() 
	{ 
		while (true) { 
			cout << "\n\t------ Welcome to the Bus "
					"Reservation System------\n\n"; 
			cout << "\t\t\t1. Register\n\t\t\t2. Log "
					"In\n\t\t\t3. Exit\t\t\t\n"; 
			cout << "\n\t\t\tEnter your choice: "; 
			int choice; 
			cin >> choice; 

			if (choice == 1) { 
				string username, password; 
				cout << "\n\t\t\tEnter username: "; 
				cin >> username; 
				cout << "\t\t\tEnter password: "; 
				cin >> password; 
				registerUser(username, password); 
			} 
			else if (choice == 2) { 
				string username, password; 
				cout << "\n\t\t\tEnter username: "; 
				cin >> username; 
				cout << "\t\t\tEnter password: "; 
				cin >> password; 
				if (authenticateUser(username, password)) { 
					cout << "\n\t\t\tLogged in "
							"successfully!\n"; 
					userMenu(username); 
				} 
				else { 
					cout << "\n\t\tAuthentication failed! "
							"Please check your username "
							"and password.\n"; 
				} 
			} 
			else if (choice == 3) { 
				cout << "\n\t\tExiting the Bus Reservation "
						"System. Goodbye!\n"; 
				break; 
			} 
		} 
	} 

	void userMenu(string username) 
	{ 
		int choice = 0; 
		while (true) { 
			cout << "\n\t----------- Welcome to the User "
					"Menu ------------\n\n"; 
			cout << "\t\t\t1. Display Routes\n\t\t\t2. "
					"Display Buses\n\t\t\t3. Book "
					"Ticket\n\t\t\t4. Cancel "
					"Ticket\n\t\t\t5. Logout\n"; 
			cout << "\n\t\t\tEnter your choice: "; 
			cin >> choice; 

			if (choice == 1) { 
				displayRoutes(); 
			} 
			else if (choice == 2) { 
				displayBuses(); 
			} 
			else if (choice == 3) { 
				bookTicket(username); 
			} 
			else if (choice == 4) { 
				cancelTicket(username); 
			} 
			else if (choice == 5) { 
				cout 
					<< "\n\t\t\tLogged out successfully.\n"; 
				break; 
			} 
		} 
	} 

private: 
	vector<User> users; 
	vector<Route> routes; 
	vector<Bus> buses; 

	void displayBusesForRoute(int selectedRoute) 
	{ 
		cout << "\t\t\tBuses for Route "
			<< routes[selectedRoute - 1].getName() 
			<< ":\n"; 
		for (int i = 0; i < buses.size(); i++) { 
			if (buses[i].getRoute().getName() 
				== routes[selectedRoute - 1].getName()) { 
				buses[i].displayBusInfo(); 
				cout << endl; 
			} 
		} 
	} 
}; 

int main() 
{ 
	BusReservationSystem system; 
	system.run(); 
	return 0; 
}