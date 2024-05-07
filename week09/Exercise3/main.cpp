#include "Train.h"

int main() {
	Train t("abc", 1, "train.txt");
	t.TransferNextRegion();
	t.TransferNextRegion();
	t.TransferNextRegion();
}
