class TransportTicket {
	unsigned id;
	char* source;
	char* destination;
	float price;

	void free();
	void copyFrom(const TransportTicket& other);

public:
	TransportTicket(unsigned id, const char* source, const char* destination, float price);
	void Print();

	TransportTicket();
	~TransportTicket();
	TransportTicket(const TransportTicket& other);
	TransportTicket& operator=(const TransportTicket& other);
	TransportTicket(TransportTicket&& other);
	TransportTicket& operator=(TransportTicket&& other);

	void SaveText(const char* fileName);
	void LoadText(const char* fileName);

	void SaveBinary(const char* fileName);
	void LoadBinary(const char* fileName);
};
