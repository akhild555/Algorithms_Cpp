int money_change(int a) {
	
	int change = a / 10;
	int remainder = a % 10;

	if (remainder == 0)
		return change;
	else
		change += remainder / 5;
		remainder = remainder % 5;
		if (remainder == 0)
			return change;
		else
			change += remainder;

	return change;	
}