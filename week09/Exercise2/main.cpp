#include "Date.h"

int main() {
	Date d1(5, 12, 2012);
	Date d2(18, 3, 1999);
	Date d3(10, 1, 2020);
	Date d4(30, 7, 1975);
	Date d5(2, 8, 1300);

	d1.StoreText("dates.txt");
	d2.StoreText("dates.txt");
	d3.StoreText("dates.txt");
	d4.StoreText("dates.txt");
	d5.StoreText("dates.txt");

	Date nd1, nd2, nd3, nd4, nd5;

	nd1.LoadText("dates.txt");
	nd2.LoadText("dates.txt");
	nd3.LoadText("dates.txt");
	nd4.LoadText("dates.txt");
	nd5.LoadText("dates.txt");

	nd5.print();
	nd4.print();
	nd3.print();
	nd2.print();
	nd1.print();
}
