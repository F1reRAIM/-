#include <vector>
#include <map>
#include <iostream>


using namespace std;

//кубик рубика 
map <int, int> face1{ {11,11},{12,12},{13,13},{14,14},{15,15},{16,16},{17,17},{18,18},{19,19} };
map <int, int> face2{ {21,21},{22,22},{23,23},{24,24},{25,25},{26,26},{27,27},{28,28},{29,29} };
map <int, int> face3{ {31,31},{32,32},{33,33},{34,34},{35,35},{36,36},{37,37},{38,38},{39,39} };
map <int, int> face4{ {41,41},{42,42},{43,43},{44,44},{45,45},{46,46},{47,47},{48,48},{49,49} };
map <int, int> face5{ {51,51},{52,52},{53,53},{54,54},{55,55},{56,56},{57,57},{58,58},{59,59} };
map <int, int> face6{ {61,61},{62,62},{63,63},{64,64},{65,65},{66,66},{67,67},{68,68},{69,69} };

int count_twist = 0;

class cub {
public:
	
	void translate(int oriented_face,int twist_massive) {
		 if(oriented_face == 3) {
				switch (twist_massive)
				{
                cout << endl;
				case 11:cout<<("  U  ");break;
				case 10:cout<<("  U'  ");break;
				case 21:cout<<("  L  ");break;
				case 20:cout<<("  L'  ");break;
				case 31:cout<<("  F  ");break;
				case 30:cout<<("  F'  ");break;
				case 41:cout<<("  R  ");break;
				case 40:cout<<("  R'  ");break;
				case 51:cout<<("  D  ");break;
				case 50:cout<<("  D'  ");break;
				case 61:cout<<("  B  ");break;
				case 60:cout<<("  B'  ");break;
				default:
					break;

				}
		 }
	}
	
	// меняет местами кубик связаного смежного угла 
	void change_edge( int clock, int& one1, int& one2, int& one3, int& two1, int& two2, int& two3, int& three1, int& three2, int& three3, int& four1, int& four2, int& four3) {
		if (clock == 1) {
			int time_adress1 = one1;
			int time_adress2 = one2;
			int time_adress3 = one3;

			one1 = four1;
			one2 = four2;
			one3 = four3;

			four1 = three1;
			four2 = three2;
			four3 = three3;

			three1 = two1;
			three2 = two2;
			three3 = two3;

			two1 = time_adress1;
			two2 = time_adress2;
			two3 = time_adress3;

		}
		else if (clock == 0) {
			int time_adress1 = one1;
			int time_adress2 = one2;
			int time_adress3 = one3;

			one1 = two1;
			one2 = two2;
			one3 = two3;

			two1 = three1;
			two2 = three2;
			two3 = three3;

			three1 = four1;
			three2 = four2;
			three3 = four3;

			four1 = time_adress1;
			four2 = time_adress2;
			four3 = time_adress3;
		}
		else {
			cout << "Ошибка направления поворота внутри!";
		}
		
	}
	//вращение реализационнакя часть выбранной внутренней стороны 
	void change(int clock, int& one, int& two, int& three, int& four, int& six, int& seven, int& eight, int& nine) {
		if (clock == 1) {
			int time_adress1 = one;
			one = seven;
			seven = nine;
			nine = three;
			three = time_adress1;

			time_adress1 = two;
			two = four;
			four = eight;
			eight = six;
			six = time_adress1;
		}
		else if (clock == 0) {
			int time_adress1 = one;
			one = three;
			three = nine;
			nine = seven;
			seven = time_adress1;

			time_adress1 = two ;
			two = six;
			six = eight;
			eight = four;
			four = time_adress1;
		}
		else {
			cout << "Ошибка направления поворота внутри!";
		}
	}
	//вывод реализационная часть 
	void print_null(map <int, int> face) {
		for (auto const& elem : face) {
			cout << elem.first << " --- " << elem.second << endl;
		}
		cout << " \n\n\n\n";
	}
 public:



	//вывод командная часть
	void print() {
		cout << endl << endl;
		print_null(face1);
		print_null(face2);
		print_null(face3);
		print_null(face4);
		print_null(face5);
		print_null(face6);
	}
    
	//вращение кубика командная чать 
	
	void twist(int twist_vector) {
		count_twist++;
		translate(3, twist_vector);
		if (twist_vector == 31) {
			change(1, face3[31], face3[32], face3[33], face3[34], face3[36], face3[37], face3[38], face3[39]);
			change_edge(1, face1[17], face1[18], face1[19], face4[41], face4[44], face4[47], face5[53], face5[52], face5[51], face2[29], face2[26], face2[23]);
		}
		else if (twist_vector == 30) {
			change(0, face3[31], face3[32], face3[33], face3[34], face3[36], face3[37], face3[38], face3[39]);
			change_edge(0, face1[17], face1[18], face1[19], face4[41], face4[44], face4[47], face5[53], face5[52], face5[51], face2[29], face2[26], face2[23]);
			
		}
		else if (twist_vector == 61) {
			change(1, face6[61], face6[62], face6[63], face6[64], face6[66], face6[67], face6[68], face6[69]);
			change_edge(1, face5[57], face5[58], face5[59], face4[49], face4[46], face4[43], face1[13], face1[12], face1[11], face2[21], face2[24], face2[27]);
		}
		else if (twist_vector == 60) {
			change(0, face6[61], face6[62], face6[63], face6[64], face6[66], face6[67], face6[68], face6[69]);
			change_edge(0, face5[57], face5[58], face5[59], face4[49], face4[46], face4[43], face1[13], face1[12], face1[11], face2[21], face2[24], face2[27]);
		}
		else if (twist_vector == 11) {
			change(1, face1[11], face1[12], face1[13], face1[14], face1[16], face1[17], face1[18], face1[19]);
			change_edge(1, face6[67], face6[68], face6[69], face4[43], face4[42], face4[41], face3[33], face3[32], face3[31], face2[23], face2[22], face2[21]);
		}
		else if (twist_vector == 10) {
			change(0, face1[11], face1[12], face1[13], face1[14], face1[16], face1[17], face1[18], face1[19]);
			change_edge(0, face6[67], face6[68], face6[69], face4[43], face4[42], face4[41], face3[33], face3[32], face3[31], face2[23], face2[22], face2[21]);
		}
		else if (twist_vector == 21) {
			change(1, face2[21], face2[22], face2[23], face2[24], face2[26], face2[27], face2[28], face2[29]);
			change_edge(1, face1[11], face1[14], face1[17], face3[31], face3[34], face3[37], face5[51], face5[54], face5[57], face6[61], face6[64], face6[67]);
		}
		else if (twist_vector == 20) {
			change(0, face2[21], face2[22], face2[23], face2[24], face2[26], face2[27], face2[28], face2[29]);
			change_edge(0, face1[11], face1[14], face1[17], face3[31], face3[34], face3[37], face5[51], face5[54], face5[57], face6[61], face6[64], face6[67]);
		}
		else if (twist_vector == 41) {
			change(1, face4[41], face4[42], face4[43], face4[44], face4[46], face4[47], face4[48], face4[49]);
			change_edge(1, face1[19], face1[16], face1[13], face6[69], face6[66], face6[63], face5[59], face5[56], face5[53], face3[39], face3[36], face3[33]);
		}
		else if (twist_vector == 40) {
			change(0, face4[41], face4[42], face4[43], face4[44], face4[46], face4[47], face4[48], face4[49]);
			change_edge(0, face1[19], face1[16], face1[13], face6[69], face6[66], face6[63], face5[59], face5[56], face5[53], face3[39], face3[36], face3[33]);
		}
		else if (twist_vector == 51) {
			change(1, face5[51], face5[52], face5[53], face5[54], face5[56], face5[57], face5[58], face5[59]);
			change_edge(1, face3[37], face3[38], face3[39], face4[47], face4[48], face4[49], face6[63], face6[62], face6[61], face2[27], face2[28], face2[29]);
		}
		else if (twist_vector == 50) {
			change(0, face5[51], face5[52], face5[53], face5[54], face5[56], face5[57], face5[58], face5[59]);
			change_edge(0, face3[37], face3[38], face3[39], face4[47], face4[48], face4[49], face6[63], face6[62], face6[61], face2[27], face2[28], face2[29]);
		}
		else
		{
			cout << "\nОшибка нет такой комбинации!!!\n";
		}
	}
	//размешает кубик 
	void stir(int max_move) {
		cout << "Stiring: ";
		srand(time(NULL));
		int var;
		cout << "Begin stiring:" << endl;
		for (int i = 0;i <= max_move;i++) {
			int probality = rand() % 12 + 1;

			switch (probality) {
			case 1:var = 11;
				break;
			case 2:var = 10;
				break;
			case 3:var = 21;
				break;
			case 4:var = 20;
				break;
			case 5:var = 31;
				break;
			case 6:var = 30;
				break;
			case 7:var = 41;
				break;
			case 8:var = 40;
				break;
			case 9:var = 51;
				break;
			case 10:var = 50;
				break;
			case 11:var = 61;
				break;
			case 12:var = 60;
				break;
			}
			cub().twist(var);
		}
		cout << "\nStiring : End stiring!\n";
	}
	//функция проверки вращения (вроде бы работает )
	  //+функция проверки на логику углов и всего остального
	void check() {
		for (int i = 0;i < 12;i++) {

			twist(31);
			twist(11);
			twist(30);
			twist(10);
			twist(41);
			twist(61);
			twist(40);
			twist(60);



			twist(51);
			twist(21);
			twist(50);
			twist(20);
		}
		
		for (int i = 0;i < 6;i++) {
			twist(31);
			twist(11);
			twist(30);
			twist(10);
		}
		for (int i = 0;i < 6;i++) {
			twist(41);
			twist(61);
			twist(40);
			twist(60);
		}
		for (int i = 0;i < 6;i++) {

			twist(51);
			twist(21);
			twist(50);
			twist(20);
		}
		if (face1[11] != 11 && face1[11] != 13 && face1[11] != 17 && face1[11] != 19 && face1[11] != 61 && face1[11] != 63 && face1[11] != 67 && face1[11] != 69 && face1[11] != 51 && face1[11] != 53 && face1[11] != 57 && face1[11] != 59 && face1[11] != 31 && face1[11] != 33 && face1[11] != 37 && face1[11] != 39 &&  face1[11] != 21 && face1[11] != 23 && face1[11] != 27 && face1[11] != 29 && face1[11] != 41 && face1[11] != 43 && face1[11] != 47 && face1[11] != 49) {
			cout << "Ошибка логики вращения угла 11!";
		}
		if (face1[13] != 11 && face1[13] != 13 && face1[13] != 17 && face1[13] != 19 && face1[13] != 61 && face1[13] != 63 && face1[13] != 67 && face1[13] != 69 && face1[13] != 51 && face1[13] != 53 && face1[13] != 57 && face1[13] != 59 && face1[13] != 31 && face1[13] != 33 && face1[13] != 37 && face1[13] != 39 &&  face1[13] != 21 && face1[13] != 23 && face1[13] != 27 && face1[13] != 29 && face1[13] != 41 && face1[13] != 43 && face1[13] != 47 && face1[13] != 49) {
			cout << "Ошибка логики вращения угла 13!";
		}
		if (face1[17] != 11 && face1[17] != 13 && face1[17] != 17 && face1[17] != 19 && face1[17] != 61 && face1[17] != 63 && face1[17] != 67 && face1[17] != 69 && face1[17] != 51 && face1[17] != 53 && face1[17] != 57 && face1[17] != 59 && face1[17] != 31 && face1[17] != 33 && face1[17] != 37 && face1[17] != 39 &&  face1[17] != 21 && face1[17] != 23 && face1[17] != 27 && face1[17] != 29 && face1[17] != 41 && face1[17] != 43 && face1[17] != 47 && face1[17] != 49) {
			cout << "Ошибка логики вращения угла 17!";
		}
		if (face1[19] != 11 && face1[19] != 13 && face1[19] != 17 && face1[19] != 19 && face1[19] != 61 && face1[19] != 63 && face1[19] != 67 && face1[19] != 69 && face1[19] != 51 && face1[19] != 53 && face1[19] != 57 && face1[19] != 59 && face1[19] != 31 && face1[19] != 33 && face1[19] != 37 && face1[19] != 39 &&  face1[19] != 21 && face1[19] != 23 && face1[19] != 27 && face1[19] != 29 && face1[19] != 41 && face1[19] != 43 && face1[19] != 47 && face1[19] != 49) {
			cout << "Ошибка логики вращения угла 19!";
		}
		if (face2[21] != 11 && face2[21] != 13 && face2[21] != 17 && face2[21] != 19 && face2[21] != 61 && face2[21] != 63 && face2[21] != 67 && face2[21] != 69 && face2[21] != 51 && face2[21] != 53 && face2[21] != 57 && face2[21] != 59 && face2[21] != 31 && face2[21] != 33 && face2[21] != 37 && face2[21] != 39 &&  face2[21] != 21 && face2[21] != 23 && face2[21] != 27 && face2[21] != 29 && face2[21] != 41 && face2[21] != 43 && face2[21] != 47 && face2[21] != 49) {
			cout << "Ошибка логики вращения угла 21!";
		}
		if (face2[23] != 11 && face2[23] != 13 && face2[23] != 17 && face2[23] != 19 && face2[23] != 61 && face2[23] != 63 && face2[23] != 67 && face2[23] != 69 && face2[23] != 51 && face2[23] != 53 && face2[23] != 57 && face2[23] != 59 && face2[23] != 31 && face2[23] != 33 && face2[23] != 37 && face2[23] != 39 &&  face2[23] != 21 && face2[23] != 23 && face2[23] != 27 && face2[23] != 29 && face2[23] != 41 && face2[23] != 43 && face2[23] != 47 && face2[23] != 49) {
			cout << "Ошибка логики вращения угла 23!";
		}
		if (face2[27] != 11 && face2[27] != 13 && face2[27] != 17 && face2[27] != 19 && face2[27] != 61 && face2[27] != 63 && face2[27] != 67 && face2[27] != 69 && face2[27] != 51 && face2[27] != 53 && face2[27] != 57 && face2[27] != 59 && face2[27] != 31 && face2[27] != 33 && face2[27] != 37 && face2[27] != 39 && face2[27] != 21 && face2[27] != 23 && face2[27] != 27 && face2[27] != 29 && face2[27] != 41 && face2[27] != 43 && face2[27] != 47 && face2[27] != 49) {
			cout << "Ошибка логики вращения угла 27!";
		}
		if (face2[29] != 11 && face2[29] != 13 && face2[29] != 17 && face2[29] != 19 && face2[29] != 61 && face2[29] != 63 && face2[29] != 67 && face2[29] != 69 && face2[29] != 51 && face2[29] != 53 && face2[29] != 57 && face2[29] != 59 && face2[29] != 31 && face2[29] != 33 && face2[29] != 37 && face2[29] != 39 && face2[29] != 21 && face2[29] != 23 && face2[29] != 27 && face2[29] != 29 && face2[29] != 41 && face2[29] != 43 && face2[29] != 47 && face2[29] != 49) {
			cout << "Ошибка логики вращения угла 29!";
		}
		if (face3[31] != 11 && face3[31] != 13 && face3[31] != 17 && face3[31] != 19 && face3[31] != 61 && face3[31] != 63 && face3[31] != 67 && face3[31] != 69 && face3[31] != 51 && face3[31] != 53 && face3[31] != 57 && face3[31] != 59 && face3[31] != 31 && face3[31] != 33 && face3[31] != 37 && face3[31] != 39 &&  face3[31] != 21 && face3[31] != 23 && face3[31] != 27 && face3[31] != 29 && face3[31] != 41 && face3[31] != 43 && face3[31] != 47 && face3[31] != 49) {
			cout << "Ошибка логики вращения угла 31!";
		}
		if (face3[33] != 11 && face3[33] != 13 && face3[33] != 17 && face3[33] != 19 && face3[33] != 61 && face3[33] != 63 && face3[33] != 67 && face3[33] != 69 && face3[33] != 51 && face3[33] != 53 && face3[33] != 57 && face3[33] != 59 && face3[33] != 31 && face3[33] != 33 && face3[33] != 37 && face3[33] != 39 &&  face3[33] != 21 && face3[33] != 23 && face3[33] != 27 && face3[33] != 29 && face3[33] != 41 && face3[33] != 43 && face3[33] != 47 && face3[33] != 49) {
			cout << "Ошибка логики вращения угла 33!";
		}
		if (face3[37] != 11 && face3[37] != 13 && face3[37] != 17 && face3[37] != 19 && face3[37] != 61 && face3[37] != 63 && face3[37] != 67 && face3[37] != 69 && face3[37] != 51 && face3[37] != 53 && face3[37] != 57 && face3[37] != 59 && face3[37] != 31 && face3[37] != 33 && face3[37] != 37 && face3[37] != 39 &&  face3[37] != 21 && face3[37] != 23 && face3[37] != 27 && face3[37] != 29 && face3[37] != 41 && face3[37] != 43 && face3[37] != 47 && face3[37] != 49) {
			cout << "Ошибка логики вращения угла 37!";
		}
		if (face3[39] != 11 && face3[39] != 13 && face3[39] != 17 && face3[39] != 19 && face3[39] != 61 && face3[39] != 63 && face3[39] != 67 && face3[39] != 69 && face3[39] != 51 && face3[39] != 53 && face3[39] != 57 && face3[39] != 59 && face3[39] != 31 && face3[39] != 33 && face3[39] != 37 && face3[39] != 39 &&  face3[39] != 21 && face3[39] != 23 && face3[39] != 27 && face3[39] != 29 && face3[39] != 41 && face3[39] != 43 && face3[39] != 47 && face3[39] != 49) {
			cout << "Ошибка логики вращения угла 39!";
		}
		if (face4[41] != 11 && face4[41] != 13 && face4[41] != 17 && face4[41] != 19 && face4[41] != 61 && face4[41] != 63 && face4[41] != 67 && face4[41] != 69 && face4[41] != 51 && face4[41] != 53 && face4[41] != 57 && face4[41] != 59 && face4[41] != 31 && face4[41] != 33 && face4[41] != 37 && face4[41] != 39 &&  face4[41] != 21 && face4[41] != 23 && face4[41] != 27 && face4[41] != 29 && face4[41] != 41 && face4[41] != 43 && face4[41] != 47 && face4[41] != 49) {
			cout << "Ошибка логики вращения угла 41!";
		}
		if (face4[43] != 11 && face4[43] != 13 && face4[43] != 17 && face4[43] != 19 && face4[43] != 61 && face4[43] != 63 && face4[43] != 67 && face4[43] != 69 && face4[43] != 51 && face4[43] != 53 && face4[43] != 57 && face4[43] != 59 && face4[43] != 31 && face4[43] != 33 && face4[43] != 37 && face4[43] != 39 &&  face4[43] != 21 && face4[43] != 23 && face4[43] != 27 && face4[43] != 29 && face4[43] != 41 && face4[43] != 43 && face4[43] != 47 && face4[43] != 49) {
			cout << "Ошибка логики вращения угла 43!";
		}
		if (face4[47] != 11 && face4[47] != 13 && face4[47] != 17 && face4[47] != 19 && face4[47] != 61 && face4[47] != 63 && face4[47] != 67 && face4[47] != 69 && face4[47] != 51 && face4[47] != 53 && face4[47] != 57 && face4[47] != 59 && face4[47] != 31 && face4[47] != 33 && face4[47] != 37 && face4[47] != 39 &&  face4[47] != 21 && face4[47] != 23 && face4[47] != 27 && face4[47] != 29 && face4[47] != 41 && face4[47] != 43 && face4[47] != 47 && face4[47] != 49) {
			cout << "Ошибка логики вращения угла 47!";
		}
		if (face4[49] != 11 && face4[49] != 13 && face4[49] != 17 && face4[49] != 19 && face4[49] != 61 && face4[49] != 63 && face4[49] != 67 && face4[49] != 69 && face4[49] != 51 && face4[49] != 53 && face4[49] != 57 && face4[49] != 59 && face4[49] != 31 && face4[49] != 33 && face4[49] != 37 && face4[49] != 39 &&  face4[49] != 21 && face4[49] != 23 && face4[49] != 27 && face4[49] != 29 && face4[49] != 41 && face4[49] != 43 && face4[49] != 47 && face4[49] != 49) {
			cout << "Ошибка логики вращения угла 49!";
		}
		if (face5[51] != 11 && face5[51] != 13 && face5[51] != 17 && face5[51] != 19 && face5[51] != 61 && face5[51] != 63 && face5[51] != 67 && face5[51] != 69 && face5[51] != 51 && face5[51] != 53 && face5[51] != 57 && face5[51] != 59 && face5[51] != 31 && face5[51] != 33 && face5[51] != 37 && face5[51] != 39 &&  face5[51] != 21 && face5[51] != 23 && face5[51] != 27 && face5[51] != 29 && face5[51] != 41 && face5[51] != 43 && face5[51] != 47 && face5[51] != 49) {
			cout << "Ошибка логики вращения угла 51!";
		}
		if (face5[53] != 11 && face5[53] != 13 && face5[53] != 17 && face5[53] != 19 && face5[53] != 61 && face5[53] != 63 && face5[53] != 67 && face5[53] != 69 && face5[53] != 51 && face5[53] != 53 && face5[53] != 57 && face5[53] != 59 && face5[53] != 31 && face5[53] != 33 && face5[53] != 37 && face5[53] != 39 &&  face5[53] != 21 && face5[53] != 23 && face5[53] != 27 && face5[53] != 29 && face5[53] != 41 && face5[53] != 43 && face5[53] != 47 && face5[53] != 49) {
			cout << "Ошибка логики вращения угла 53!";
		}
		if (face5[57] != 11 && face5[57] != 13 && face5[57] != 17 && face5[57] != 19 && face5[57] != 61 && face5[57] != 63 && face5[57] != 67 && face5[57] != 69 && face5[57] != 51 && face5[57] != 53 && face5[57] != 57 && face5[57] != 59 && face5[57] != 31 && face5[57] != 33 && face5[57] != 37 && face5[57] != 39 &&  face5[57] != 21 && face5[57] != 23 && face5[57] != 27 && face5[57] != 29 && face5[57] != 41 && face5[57] != 43 && face5[57] != 47 && face5[57] != 49) {
			cout << "Ошибка логики вращения угла 57!";
		}
		if (face5[59] != 11 && face5[59] != 13 && face5[59] != 17 && face5[59] != 19 && face5[59] != 61 && face5[59] != 63 && face5[59] != 67 && face5[59] != 69 && face5[59] != 51 && face5[59] != 53 && face5[59] != 57 && face5[59] != 59 && face5[59] != 31 && face5[59] != 33 && face5[59] != 37 && face5[59] != 39 &&  face5[59] != 21 && face5[59] != 23 && face5[59] != 27 && face5[59] != 29 && face5[59] != 41 && face5[59] != 43 && face5[59] != 47 && face5[59] != 49) {
			cout << "Ошибка логики вращения угла 89!";
		}
		if (face6[61] != 11 && face6[61] != 13 && face6[61] != 17 && face6[61] != 19 && face6[61] != 61 && face6[61] != 63 && face6[61] != 67 && face6[61] != 69 && face6[61] != 51 && face6[61] != 53 && face6[61] != 57 && face6[61] != 59 && face6[61] != 31 && face6[61] != 33 && face6[61] != 37 && face6[61] != 39 &&  face6[61] != 21 && face6[61] != 23 && face6[61] != 27 && face6[61] != 29 && face6[61] != 41 && face6[61] != 43 && face6[61] != 47 && face6[61] != 49) {
			cout << "Ошибка логики вращения угла 61!";
		}
		if (face6[63] != 11 && face6[63] != 13 && face6[63] != 17 && face6[63] != 19 && face6[63] != 61 && face6[63] != 63 && face6[63] != 67 && face6[63] != 69 && face6[63] != 51 && face6[63] != 53 && face6[63] != 57 && face6[63] != 59 && face6[63] != 31 && face6[63] != 33 && face6[63] != 37 && face6[63] != 39 &&  face6[63] != 21 && face6[63] != 23 && face6[63] != 27 && face6[63] != 29 && face6[63] != 41 && face6[63] != 43 && face6[63] != 47 && face6[63] != 49) {
			cout << "Ошибка логики вращения угла 63!";
		}
		if (face6[67] != 11 && face6[67] != 13 && face6[67] != 17 && face6[67] != 19 && face6[67] != 61 && face6[67] != 63 && face6[67] != 67 && face6[67] != 69 && face6[67] != 51 && face6[67] != 53 && face6[67] != 57 && face6[67] != 59 && face6[67] != 31 && face6[67] != 33 && face6[67] != 37 && face6[67] != 39 &&  face6[67] != 21 && face6[67] != 23 && face6[67] != 27 && face6[67] != 29 && face6[67] != 41 && face6[67] != 43 && face6[67] != 47 && face6[67] != 49) {
			cout << "Ошибка логики вращения угла 67!";
		}
		if (face6[69] != 11 && face6[69] != 13 && face6[69] != 17 && face6[69] != 19 && face6[69] != 61 && face6[69] != 63 && face6[69] != 67 && face6[69] != 69 && face6[69] != 51 && face6[69] != 53 && face6[69] != 57 && face6[69] != 59 && face6[69] != 31 && face6[69] != 33 && face6[69] != 37 && face6[69] != 39 &&  face6[69] != 21 && face6[69] != 23 && face6[69] != 27 && face6[69] != 29 && face6[69] != 41 && face6[69] != 43 && face6[69] != 47 && face6[69] != 49) {
			cout << "Ошибка логики вращения угла 69!";
		}
	}
	void twist_massiv(vector<int> twist_massiv_vector) {
		for (auto const elem : twist_massiv_vector) {
			twist(elem);
		}
	}

	void white_cross() {
		cout << "\nBegin assembling : White cross\n";
		//сборка белого креста или нижнего (желтого или 5)
		//from 52
		bool white_cross_retry = 1;
		while(white_cross_retry){
			if (face5[52] == 12 || face5[52] == 14 || face5[52] == 16 || face5[52] == 18) {
				if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
					twist(31);
					twist(31);
				}
				else {
					if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
						twist(10);
						twist(31);
						twist(31);
					}
					else {
						if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
							twist(11);
							twist(31);
							twist(31);
						}
						else {
							if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
								twist(11);
								twist(11);
								twist(31);
								twist(31);
							}
						}
					}
				}
				continue;
			}

			//from 54
			if (face5[54] == 12 || face5[54] == 14 || face5[54] == 16 || face5[54] == 18) {
				if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
					twist(21);
					twist(21);
				}
				else {
					if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
						twist(10);
						twist(21);
						twist(21);
					}
					else {
						if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
							twist(11);
							twist(21);
							twist(21);
						}
						else {
							if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
								twist(11);
								twist(11);
								twist(21);
								twist(21);
							}
						}
					}
				}
				continue;
			}
			//from 56
			if (face5[56] == 12 || face5[56] == 14 || face5[56] == 16 || face5[56] == 18) {
				if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
					twist(41);
					twist(41);
				}
				else {
					if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
						twist(11);
						twist(41);
						twist(41);
					}
					else {
						if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
							twist(10);
							twist(41);
							twist(41);
						}
						else {
							if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
								twist(11);
								twist(11);
								twist(41);
								twist(41);
							}
						}
					}
				}
				continue;
			}
			//from 58
			if (face5[58] == 12 || face5[58] == 14 || face5[58] == 16 || face5[58] == 18) {

				if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
					twist(61);
					twist(61);
				}
				else {
					if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
						twist(11);
						twist(61);
						twist(61);
					}
					else {
						if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
							twist(10);
							twist(61);
							twist(61);
						}
						else {
							if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
								twist(11);
								twist(11);
								twist(61);
								twist(61);
							}
						}
					}
				}
				continue;
			}
			//Сборка креста с боковых нижних сторон 
			//from 38
			if (face3[38] == 12 || face3[38] == 14 || face3[38] == 16 || face3[38] == 18) {
				if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
					twist(30);
					twist(10);
					twist(41);

				}
				else {
					if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
						twist(31);
						twist(20);
						twist(30);
					}
					else {
						if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
							twist(30);
							twist(41);
							twist(31);
						}
						else {
							if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
								twist(50);
								twist(21);
								twist(60);
								twist(60);
							}
						}
					}
				}
				continue;
			}


			//from 48
			if (face4[48] == 12 || face4[48] == 14 || face4[48] == 16 || face4[48] == 18) {
				if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
					twist(40);
					twist(10);
					twist(61);
				}
				else {
					if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
						twist(41);
						twist(30);
						twist(40);
					}
					else {
						if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
							twist(40);
							twist(60);
							twist(41);
						}
						else {
							if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
								twist(50);
								twist(31);
								twist(20);
								twist(30);
							}
						}
					}
				}
				continue;
			}


			//from 62
			if (face6[62] == 12 || face6[62] == 14 || face6[62] == 16 || face6[62] == 18) {
				if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
					twist(60);
					twist(10);
					twist(21);
				}
				else {
					if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
						twist(61);
						twist(40);
						twist(60);
					}
					else {
						if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
							twist(60);
							twist(21);
							twist(61);
						}
						else {
							if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
								twist(50);
								twist(41);
								twist(30);
								twist(40);
							}
						}
					}
				}
				continue;
			}


			//from 28
			if (face2[28] == 12 || face2[28] == 14 || face2[28] == 16 || face2[28] == 18) {
				if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
					twist(20);
					twist(10);
					twist(31);
				}
				else {
					if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
						twist(21);
						twist(60);
						twist(20);
					}
					else {
						if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
							twist(20);
							twist(31);
							twist(21);
						}
						else {
							if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
								twist(50);
								twist(61);
								twist(40);
								twist(60);
							}
						}
					}
				}
				continue;
			}


			//сборка средних граней боковых сторон 
			//from 34
			if (face3[34] == 12 || face3[34] == 14 || face3[34] == 16 || face3[34] == 18) {
				if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
					twist(11);
					twist(20);
				}
				else {
					if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
						twist(20);
					}
					else {
						if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
							twist(11);
							twist(11);
							twist(20);
						}
						else {
							if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
								twist(10);
								twist(20);
							}
						}
					}
				}
				continue;
			}
			//from 36
			if (face3[36] == 12 || face3[36] == 14 || face3[36] == 16 || face3[36] == 18) {
				if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
					twist(10);
					twist(41);
				}
				else {
					if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
						twist(10);
						twist(10);
						twist(41);
					}
					else {
						if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
							twist(41);
						}
						else {
							if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
								twist(11);
								twist(41);
							}
						}
					}
				}
				continue;
			}
			//from 44
			if (face4[44] == 12 || face4[44] == 14 || face4[44] == 16 || face4[44] == 18) {
				if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
					twist(11);
					twist(30);
				}
				else {
					if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
						twist(30);
					}
					else {
						if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
							twist(11);
							twist(11);
							twist(30);
						}
						else {
							if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
								twist(10);
								twist(30);
							}
						}
					}
				}
				continue;
			}
			//from 46
			if (face4[46] == 12 || face4[46] == 14 || face4[46] == 16 || face4[46] == 18) {
				if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
					twist(10);
					twist(61);
				}
				else {
					if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
						twist(10);
						twist(10);
						twist(61);
					}
					else {
						if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
							twist(61);
						}
						else {
							if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
								twist(11);
								twist(61);
							}
						}
					}
				}
				continue;
			}
			//from 66
			if (face6[66] == 12 || face6[66] == 14 || face6[66] == 16 || face6[66] == 18) {
				if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
					twist(10);
					twist(40);
				}
				else {
					if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
						twist(40);
					}
					else {
						if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
							twist(10);
							twist(10);
							twist(40);
						}
						else {
							if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
								twist(10);
								twist(40);
							}
						}
					}
				}
				continue;
			}
			//from 64
			if (face6[64] == 12 || face6[64] == 14 || face6[64] == 16 || face6[64] == 18) {
				if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
					twist(10);
					twist(40);
				}
				else {
					if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
						twist(10);
						twist(10);
						twist(21);
					}
					else {
						if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
							twist(21);
						}
						else {
							if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
								twist(11);
								twist(21);
							}
						}
					}
				}
				continue;
			}
			//from 24
			if (face2[24] == 12 || face2[24] == 14 || face2[24] == 16 || face2[24] == 18) {
				if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
					twist(11);
					twist(60);
				}
				else {
					if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
						twist(60);
					}
					else {
						if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
							twist(11);
							twist(11);
							twist(60);
						}
						else {
							if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
								twist(10);
								twist(60);
							}
						}
					}
				}
				continue;
			}
			//from 26
			if (face2[26] == 12 || face2[26] == 14 || face2[26] == 16 || face2[26] == 18) {
				if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
					twist(10);
					twist(31);
				}
				else {
					if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
						twist(10);
						twist(10);
						twist(31);
					}
					else {
						if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
							twist(31);
						}
						else {
							if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
								twist(11);
								twist(31);
							}
						}
					}
				}
				continue;
			}
			//сборка белого креста с верхних боковых сторон 
			if (face3[32] == 12 || face3[32] == 14 || face3[32] == 16 || face3[32] == 18) {
				if (face1[18] != 12 && face1[18] != 14 && face1[18] != 16 && face1[18] != 18) {
					twist(30);
					twist(11);
					twist(20);
				}
				continue;
			}
			if (face4[42] == 12 || face4[42] == 14 || face4[42] == 16 || face4[42] == 18) {
				if (face1[16] != 12 && face1[16] != 14 && face1[16] != 16 && face1[16] != 18) {
					twist(40);
					twist(11);
					twist(30);
				}
				continue;
			}
			if (face6[68] == 12 || face6[68] == 14 || face6[68] == 16 || face6[68] == 18) {
				if (face1[12] != 12 && face1[12] != 14 && face1[12] != 16 && face1[12] != 18) {
					twist(60);
					twist(11);
					twist(40);
				}
				continue;
			}
			if (face2[22] == 12 || face2[22] == 14 || face2[22] == 16 || face2[22] == 18) {
				if (face1[14] != 12 && face1[14] != 14 && face1[14] != 16 && face1[14] != 18) {
					twist(20);
					twist(11);
					twist(60);
				}
				continue;
			}
			if ((face1[12] == 12 || face1[12] == 14 || face1[12] == 16 || face1[12] == 18) && (face1[14] == 12 || face1[14] == 14 || face1[14] == 16 || face1[14] == 18) && (face1[16] == 12 || face1[16] == 14 || face1[16] == 16 || face1[16] == 18) && (face1[18] == 12 || face1[18] == 14 || face1[18] == 16 || face1[18] == 18)) {
				if (face1[12] == 12 && face1[14] == 14 && face1[16] == 16 && face1[18] == 18) {
					white_cross_retry = 0;
					cout << "\nEnd assembling : White cross ";
					break;
				}
				twist(11);
				if (face1[12] == 12 && face1[14] == 14 && face1[16] == 16 && face1[18] == 18) {
					white_cross_retry = 0;
					cout << "\nEnd assembling : White cross  ";
					break;
				}
				twist(11);
				if (face1[12] == 12 && face1[14] == 14 && face1[16] == 16 && face1[18] == 18) {
					white_cross_retry = 0;
					cout << "\nEnd assembling : White cross  ";
					break;
				}
				twist(11);
				if (face1[12] == 12 && face1[14] == 14 && face1[16] == 16 && face1[18] == 18) {
					white_cross_retry = 0;
					cout << "\nEnd assembling :  White cross ";
					break;
				}
				twist(11);

				//сборка боковых граней
				while (face1[12] != 12 || face1[14] != 14 || face1[16] != 16 || face1[18] != 18) {

					if (face3[32] == 32) {
						if (face4[42] == 42) {
							twist(61);
							twist(11);
							twist(60);
							twist(10);
							twist(61);
						}
						if (face2[22] == 22) {
							twist(41);
							twist(11);
							twist(40);
							twist(10);
							twist(41);
						}
						if (face6[68] == 68) {
							twist(40);
							twist(11);
							twist(11);
							twist(41);
							twist(11);
							twist(11);
							twist(40);
						}
						else {
							twist(41);
							twist(11);
							twist(40);
							twist(10);
							twist(41);
						}

					}
					if (face1[12] == 12 && face1[14] == 14 && face1[16] == 16 && face1[18] == 18) {
						white_cross_retry = 0;
						cout << "\nEnd assembling : White cross  ";
						break;
					}
					else {
						twist(11);

					}
					continue;
				}
			}
	    }
	}
			
	
	bool check_corner_to_white(int one, int two, int three) {
		if ((one == 11 || one == 13 || one == 17 || one == 19) || (two == 11 || two == 13 || two == 17 || two == 19) || (three == 11 || three == 13 || three == 17 || three == 19)) {
			return true;
		}
		else {
			return false;
		}
	}

	bool check_corner_to_color(int one, int two, int three, int four) {
		if (one == four || two == four || three == four)
		{
			return true;
		}
		else {
			return false;
		}
	}
	

	void f1l( ) {
		cout << "\nBegin assembling: F1L\n";
		bool f1l_retry = 1;
		while (f1l_retry) {
			if (face1[11] == 11 && face1[13] == 13 && face1[17] == 17 && face1[19] == 19) {
				f1l_retry = 0;
				cout << "\nEnd assembling: F1L\n";
				break;
			}
			else {
				if (face1[11] != 11) {
					twist_massiv({ 61,51,60,50 });
				}
				if (face1[13] != 13) {
					twist_massiv({ 41,51,40,50 });
				}
				if (face1[17] != 17) {
					twist_massiv({ 21,51,20,50 });
				}
				if (face1[19] != 19) {
					twist_massiv({ 31,51,30,50 });
				}
			}
			if (check_corner_to_white(face5[59], face6[63], face4[49]) || check_corner_to_white(face5[53], face4[47], face3[39]) || check_corner_to_white(face5[51], face3[37], face2[29]) || check_corner_to_white(face5[57], face2[27], face6[61])) {
				if (check_corner_to_white(face5[59], face6[63], face4[49])) {

					if (check_corner_to_color(face5[59], face6[63], face4[49], 13)) {
						while (face1[13] != 13) {
							twist_massiv({ 41,51,40,50 });
						}
					}
					if (check_corner_to_color(face5[59], face6[63], face4[49], 11)) {
						twist(51);
						while (face1[11] != 11) {
							twist_massiv({ 61,51,60,50 });
						}
					}
					if (check_corner_to_color(face5[59], face6[63], face4[49], 17)) {
						twist(51);
						twist(51);
						while (face1[17] != 17) {
							twist_massiv({ 21,51,20,50 });
						}
					}
					if (check_corner_to_color(face5[59], face6[63], face4[49], 19)) {
						twist(50);
						while (face1[19] != 19) {
							twist_massiv({ 31,51,30,50 });
						}
					}

				}
				
				if (check_corner_to_white(face5[53], face4[47], face3[39])) {
					if (check_corner_to_color(face5[53], face4[47], face3[39], 13)) {
						twist(51);
						while (face1[13] != 13) {
							twist_massiv({ 41,51,40,50 });
						}
					}
					if (check_corner_to_color(face5[53], face4[47], face3[39], 11)) {
						twist(51);
						twist(51);
						while (face1[11] != 11) {
							twist_massiv({ 61,51,60,50 });
						}
					}
					if (check_corner_to_color(face5[53], face4[47], face3[39], 17)) {
						twist(50);
						while (face1[17] != 17) {
							twist_massiv({ 21,51,20,50 });
						}
					}
					if (check_corner_to_color(face5[53], face4[47], face3[39], 19)) {

						while (face1[19] != 19) {
							twist_massiv({ 31,51,30,50 });
						}
					}
				}
				
				if (check_corner_to_white(face5[51], face3[37], face2[29])) {
					if (check_corner_to_color(face5[51], face3[37], face2[29], 13)) {
						twist(51);
						twist(51);

						while (face1[13] != 13) {
							twist_massiv({ 41,51,40,50 });
						}
					}
					if (check_corner_to_color(face5[51], face3[37], face2[29], 11)) {
						twist(50);
						while (face1[11] != 11) {
							twist_massiv({ 61,51,60,50 });
						}
					}
					if (check_corner_to_color(face5[51], face3[37], face2[29], 17)) {

						while (face1[17] != 17) {
							twist_massiv({ 21,51,20,50 });
						}
					}
					if (check_corner_to_color(face5[51], face3[37], face2[29], 19)) {
						twist(51);
						while (face1[19] != 19) {
							twist_massiv({ 31,51,30,50 });
						}
					}
				}
				
				if (check_corner_to_white(face5[57], face2[27], face6[61])) {
					if (check_corner_to_color(face5[57], face2[27], face6[61], 13)) {

						twist(50);
						while (face1[13] != 13) {
							twist_massiv({ 41,51,40,50 });
						}
					}
					if (check_corner_to_color(face5[57], face2[27], face6[61], 11)) {

						while (face1[11] != 11) {
							twist_massiv({ 61,51,60,50 });
						}
					}
					if (check_corner_to_color(face5[57], face2[27], face6[61], 17)) {
						twist(51);
						while (face1[17] != 17) {
							twist_massiv({ 21,51,20,50 });
						}
					}
					if (check_corner_to_color(face5[57], face2[27], face6[61], 19)) {
						twist(51);
						twist(51);
						while (face1[19] != 19) {
							twist_massiv({ 31,51,30,50 });
						}
					}
				}
			}
			
		}
	}
	bool check_edge_to_color(int one, int two, int three, int four,int check_color) {
		if (one == check_color || two == check_color || three == check_color || four == check_color)
		{
			return true;
		}
		else {
			return false;
		}
	}

	

	void f2l() {
		cout << "\nBegin assembling: F2L\n";
		while (face3[34] != 34 || face2[24] != 24 || face6[66] != 66 || face4[44] != 44) {
			//52
			if (check_edge_to_color(face5[52], face5[54], face5[56], face5[58],24 ) || check_edge_to_color(face5[52], face5[54], face5[56], face5[58], 26) || check_edge_to_color(face5[52], face5[54], face5[56], face5[58], 34) || check_edge_to_color(face5[52], face5[54], face5[56], face5[58], 36) || check_edge_to_color(face5[52], face5[54], face5[56], face5[58], 44) || check_edge_to_color(face5[52], face5[54], face5[56], face5[58], 46) || check_edge_to_color(face5[52], face5[54], face5[56], face5[58], 66) || check_edge_to_color(face5[52], face5[54], face5[56], face5[58], 64)) {
				if (face5[52] == 24) {
					twist_massiv({ 51,20,51,21,51,61,50,60 });
					if (face2[24] != 24) {
						cout << "Ошибка логики вращения F2L к 24 в 52!";
					}
				}
				if (face5[52] == 26) {
					twist_massiv({ 51,21,50,20,50,30,51,31 });
					if (face2[26] != 26) {
						cout << "Ошибка логики вращения F2L к 26 в 52!";
					}
				}
				if (face5[52] == 34) {
					twist_massiv({ 50,50,30,51,31,51,21,50,20 });
					if (face3[34] != 34) {
						cout << "Ошибка логики вращения F2L к 34 в 52!";
					}
				}
				if (face5[52] == 36) {
					twist_massiv({ 51, 51,31,50,30,50,40,51,41 });
					if (face3[36] != 36) {
						cout << "Ошибка логики вращения F2L к 36 в 52!";
					}
				}
				if (face5[52] == 44) {
					twist_massiv({ 50,40,51,41,51,31,50,30 });
					if (face4[44] != 44) {
						cout << "Ошибка логики вращения F2L к 44 в 52!";
					}
				}
				if (face5[52] == 46) {
					twist_massiv({ 50,41,50,40,50,60,51,61 });
					if (face4[46] != 46) {
						cout << "Ошибка логики вращения F2L к 46 в 52!";
					}
				}
				if (face5[52] == 66) {
					twist_massiv({ 60,51,61,51,41,50,40, });
					if (face6[66] != 66) {
						cout << "Ошибка логики вращения F2L к 66 в 52!";
					}
				}
				if (face5[52] == 64) {
					twist_massiv({ 61,50,60,50,20,51,21 });
					if (face6[64] != 64) {
						cout << "Ошибка логики вращения F2L к 64 в 52!";
					}
				}

				////////////////////////////////////////////////


				if (face5[54] == 24) {
					twist_massiv({ 51,51,20,51,21,51,61,50,60 });
					if (face2[24] != 24) {
						cout << "Ошибка логики вращения F2L к 24 в 54!";
					}
				}
				if (face5[54] == 26) {
					twist_massiv({ 51,51,21,50,20,50,30,51,31 });
					if (face2[26] != 26) {
						cout << "Ошибка логики вращения F2L к 26 в 54!";
					}
				}
				if (face5[54] == 34) {
					twist_massiv({ 50,30,51,31,51,21,50,20 });
					if (face3[34] != 34) {
						cout << "Ошибка логики вращения F2L к 34 в 54!";
					}
				}
				if (face5[54] == 36) {
					twist_massiv({ 50,31,50,30,50,40,51,41 });
					if (face3[36] != 36) {
						cout << "Ошибка логики вращения F2L к 36 в 54!";
					}
				}
				if (face5[54] == 44) {
					twist_massiv({ 40,51,41,51,31,50,30 });
					if (face4[44] != 44) {
						cout << "Ошибка логики вращения F2L к 44 в 54!";
					}
				}
				if (face5[54] == 46) {
					twist_massiv({ 41,50,40,50,60,51,61 });
					if (face4[46] != 46) {
						cout << "Ошибка логики вращения F2L к 46 в 54!";
					}
				}
				if (face5[54] == 66) {
					twist_massiv({ 51,60,51,61,51,41,50,40, });
					if (face6[66] != 66) {
						cout << "Ошибка логики вращения F2L к 66 в 54!";
					}
				}
				if (face5[54] == 64) {
					twist_massiv({ 51, 61,50,60,50,20,51,21 });
					if (face6[64] != 64) {
						cout << "Ошибка логики вращения F2L к 64 в 54!";
					}
				}

				///////////////////////////////


				if (face5[56] == 24) {
					twist_massiv({ 20,51,21,51,61,50,60 });
					if (face2[24] != 24) {
						cout << "Ошибка логики вращения F2L к 24 в 56!";
					}
				}
				if (face5[56] == 26) {
					twist_massiv({ 21,50,20,50,30,51,31 });
					if (face2[26] != 26) {
						cout << "Ошибка логики вращения F2L к 26 в 56!";
					}
				}
				if (face5[56] == 34) {
					twist_massiv({ 51,30,51,31,51,21,50,20 });
					if (face3[34] != 34) {
						cout << "Ошибка логики вращения F2L к 34 в 56!";
					}
				}
				if (face5[56] == 36) {
					twist_massiv({ 51,31,50,30,50,40,51,41 });
					if (face3[36] != 36) {
						cout << "Ошибка логики вращения F2L к 36 в 56!";
					}
				}
				if (face5[56] == 44) {
					twist_massiv({ 50,50,40,51,41,51,31,50,30 });
					if (face4[44] != 44) {
						cout << "Ошибка логики вращения F2L к 44 в 56!";
					}
				}
				if (face5[56] == 46) {
					twist_massiv({ 50,50, 41,50,40,50,60,51,61 });
					if (face4[46] != 46) {
						cout << "Ошибка логики вращения F2L к 46 в 56!";
					}
				}
				if (face5[56] == 66) {
					twist_massiv({ 50,60,51,61,51,41,50,40, });
					if (face6[66] != 66) {
						cout << "Ошибка логики вращения F2L к 66 в 56!";
					}
				}
				if (face5[56] == 64) {
					twist_massiv({ 50, 61,50,60,50,20,51,21 });
					if (face6[64] != 64) {
						cout << "Ошибка логики вращения F2L к 64 в 56!";
					}
				}

				/////////////////

				if (face5[58] == 24) {
					twist_massiv({ 50,20,51,21,51,61,50,60 });
					if (face2[24] != 24) {
						cout << "Ошибка логики вращения F2L к 24 в 58!";
					}
				}
				if (face5[58] == 26) {
					twist_massiv({ 50,21,50,20,50,30,51,31 });
					if (face2[26] != 26) {
						cout << "Ошибка логики вращения F2L к 26 в 58!";
					}
				}
				if (face5[58] == 34) {
					twist_massiv({ 30,51,31,51,21,50,20 });
					if (face3[34] != 34) {
						cout << "Ошибка логики вращения F2L к 34 в 58!";
					}
				}
				if (face5[58] == 36) {
					twist_massiv({ 31,50,30,50,40,51,41 });
					if (face3[36] != 36) {
						cout << "Ошибка логики вращения F2L к 36 в 58!";
					}
				}
				if (face5[58] == 44) {
					twist_massiv({ 51,40,51,41,51,31,50,30 });
					if (face4[44] != 44) {
						cout << "Ошибка логики вращения F2L к 44 в 58!";
					}
				}
				if (face5[58] == 46) {
					twist_massiv({ 51, 41,50,40,50,60,51,61 });
					if (face4[46] != 46) {
						cout << "Ошибка логики вращения F2L к 46 в 58!";
					}
				}
				if (face5[58] == 66) {
					twist_massiv({ 51,51,60,51,61,51,41,50,40, });
					if (face6[66] != 66) {
						cout << "Ошибка логики вращения F2L к 66 в 58!";
					}
				}
				if (face5[58] == 64) {
					twist_massiv({ 51,51, 61,50,60,50,20,51,21 });
					if (face6[64] != 64) {
						cout << "Ошибка логики вращения F2L к 64 в 58!";
					}
				}
			}
			else {
				if (face2[24]!= 24) {
					twist_massiv({  61,50,60,50,20,51,21 });
				}
				if (face6[66] != 66) {
					twist_massiv({ 60,51,61,51,41,50,40, });
				}
				if (face4[44] != 44) {
					twist_massiv({ 40,51,41,51,31,50,30 });
				}
				if (face3[34] != 34) {
					twist_massiv({ 30,51,31,51,21,50,20 });
				}
			}
	    }
		cout << "\nEnd assembling: F2L\n";
    }
	bool check_yellow_cross(int one) {
		if (one == 52 || one == 54 || one == 56 || one == 58 ) {
			return 1;
		}
		else {
			return 0;
		}
	}

	void yellov_cross() {
		cout << "Begin assembling: Yellow cross\n";
		while (!check_yellow_cross(face5[52]) || !check_yellow_cross(face5[54]) || !check_yellow_cross(face5[56]) || !check_yellow_cross(face5[58])) {
			if (!check_yellow_cross(face5[52]) && !check_yellow_cross(face5[54]) && !check_yellow_cross(face5[56]) && !check_yellow_cross(face5[58])) {
				twist_massiv({ 31,21,51,20,50,30 ,31,21,51,20,50,30 ,41,31,51,30,50,40 });
			}
			else {
				if (check_yellow_cross(face5[52]) && check_yellow_cross(face5[58])) {
					twist_massiv({ 21,61,51,60,50,20 });
				}
				else {
					if (check_yellow_cross(face5[56]) && check_yellow_cross(face5[54])) {
						twist_massiv({ 31,21,51,20,50,30 });
					}
					else {
						if (check_yellow_cross(face5[52]) && check_yellow_cross(face5[54])) {
							twist_massiv({ 61,41,51,40,50,60  ,61,41,51,40,50,60 });
						}
						else {
							if (check_yellow_cross(face5[52]) && check_yellow_cross(face5[56])) {
								twist_massiv({ 21,61,51,60,50,20 ,21,61,51,60,50,20 });
							}
							else {
								if (check_yellow_cross(face5[58]) && check_yellow_cross(face5[56])) {
									twist_massiv({ 31,21,51,20,50,30 ,31,21,51,20,50,30 });
								}
								else {
									if (check_yellow_cross(face5[58]) && check_yellow_cross(face5[54])) {
										twist_massiv({ 41,31,51,30,50,40 ,41,31,51,30,50,40 });
									}
								}
							}

						}
					}
				}
			}
		}
		int retrying = 0;
		while (face2[28] != 28 || face3[38] != 38 || face4[48] != 48 || face6[62] != 62) {
			
			if (face2[28] == 28 && face3[38] != 38 && face4[48] != 48 && face6[62] != 62) {
				twist_massiv({ 61,51,60,51,61,51,51,60 });
				continue;
			}
			if (face2[28] != 28 && face3[38] == 38 && face4[48] != 48 && face6[62] != 62) {
				twist_massiv({ 21,51,20,51,21,51,51,20 });
				continue;
			}
			if (face2[28] != 28 && face3[38] != 38 && face4[48] == 48 && face6[62] != 62) {
				twist_massiv({ 31,51,30,51,31,51,51,30 });
				continue;
			}
			if (face2[28] != 28 && face3[38] != 38 && face4[48] != 48 && face6[62] == 62) {
				twist_massiv({ 41,51,40,51,41,51,51,40 });
				continue;
			}
			else {
				twist(51);
				if (retrying == 4 || retrying == 9 || retrying == 14 || retrying == 19) {
					twist_massiv({ 31,21,51,20,50,30  });
				}
				if (retrying > 23) {
					retrying = 0;
					continue;
				}
			}
			retrying++;
		}
		cout << "\nEnd assembling: Yellow cross\n";

	}
	void last_corners() {
		cout << "\nBegin assembling: Last corners\n";
		while (face5[51] != 51 || face5[53] != 53 || face5[57] != 57 || face5[59] != 59) {
			while ((face5[51] != 51 && face5[51] != 37 && face5[51] != 29) || (face5[53] != 53 && face5[53] != 47 && face5[53] != 39) || (face5[57] != 57 && face5[57] != 27 && face5[57] != 61) || (face5[59] != 59 && face5[59] != 63 && face5[59] != 49)) {
				if (face5[51] == 51 || face5[51] == 37 || face5[51] == 29) {
					while ((face5[51] != 51 && face5[51] != 37 && face5[51] != 29) || (face5[53] != 53 && face5[53] != 47 && face5[53] != 39) || (face5[57] != 57 && face5[57] != 27 && face5[57] != 61) || (face5[59] != 59 && face5[59] != 63 && face5[59] != 49)) {
						twist_massiv({ 51,21,50,40,51,20,50,41 });
					}
				}
				else {
					if (face5[53] == 53 || face5[53] == 47 || face5[53] == 39) {
						while ((face5[51] != 51 && face5[51] != 37 && face5[51] != 29) || (face5[53] != 53 && face5[53] != 47 && face5[53] != 39) || (face5[57] != 57 && face5[57] != 27 && face5[57] != 61) || (face5[59] != 59 && face5[59] != 63 && face5[59] != 49)) {
							twist_massiv({ 51,31,50,60,51,30,50,61 });
						}

					}
					else {
						if (face5[57] == 57 || face5[57] == 27 || face5[57] == 61) {
							while ((face5[51] != 51 && face5[51] != 37 && face5[51] != 29) || (face5[53] != 53 && face5[53] != 47 && face5[53] != 39) || (face5[57] != 57 && face5[57] != 27 && face5[57] != 61) || (face5[59] != 59 && face5[59] != 63 && face5[59] != 49)) {
								twist_massiv({ 51,61,50,30,51,60,50,31 });
							}

						}
						else {
							if (face5[59] == 59 || face5[59] == 63 || face5[59] == 49) {
								while ((face5[51] != 51 && face5[51] != 37 && face5[51] != 29) || (face5[53] != 53 && face5[53] != 47 && face5[53] != 39) || (face5[57] != 57 && face5[57] != 27 && face5[57] != 61) || (face5[59] != 59 && face5[59] != 63 && face5[59] != 49)) {
									twist_massiv({ 51,41,50,20,51,40,50,21 });
								}

							}
							else {

								twist_massiv({ 51,21,50,40,51,20,50,41 });

							}
						}
					}
				}
			}
				if (face5[51] != 51) {
					while (face5[51] != 51) {
						twist_massiv({ 31,11,30,10 });
					}
					if (face5[53] != 53) {
						twist(50);
						while (face5[51] != 53) {
							twist_massiv({ 31,11,30,10 });
						}
						twist(51);
					}
					if (face5[57] != 57) {
						twist(51);
						while (face5[51] != 57) {
							twist_massiv({ 31,11,30,10 });
						}
						twist(50);
					}
					if (face5[59] != 59) {
						twist(50);
						twist(50);
						while (face5[51] != 59) {
							twist_massiv({ 31,11,30,10 });
						}
						twist(50);
						twist(50);
					}
					continue;
				}
				else {
					if (face5[53] != 53) {
						while (face5[53] != 53) {
							twist_massiv({ 41,11,40,10 });
						}
						if (face5[51] != 51) {
							twist(51);
							while (face5[53] != 51) {
								twist_massiv({ 41,11,40,10 });
							}
							twist(50);
						}
						if (face5[57] != 57) {
							twist(50);
							twist(50);
							while (face5[53] != 57) {
								twist_massiv({ 41,11,40,10 });
							}
							twist(50);
							twist(50);
						}
						if (face5[59] != 59) {
							twist(50);
							while (face5[53] != 59) {
								twist_massiv({ 41,11,40,10 });
							}
							twist(51);
						}
						continue;
					}
					

					else {
						if (face5[57] != 57) {
							while (face5[57] != 57) {
								twist_massiv({ 21,11,20,10 });
							}
							if (face5[51] != 51) {
								twist(50);
								while (face5[57] != 51) {
									twist_massiv({ 21,11,20,10 });
								}
								twist(51);
							}
							if (face5[53] != 53) {
								twist(50);
								twist(50);
								while (face5[57] != 53) {
									twist_massiv({ 21,11,20,10 });
								}
								twist(50);
								twist(50);
							}
							if (face5[59] != 59) {
								twist(51);
								while (face5[57] != 59) {
									twist_massiv({ 21,11,20,10 });
								}
								twist(50);
							}
                        continue;
						}
						
						else {
							if (face5[59] != 59) {
								while (face5[59] != 59) {
									twist_massiv({ 61,11,60,10 });
								}
								if (face5[51] != 51) {
									twist(50);
									twist(50);
									while (face5[59] != 51) {
										twist_massiv({ 61,11,60,10 });
									}
									twist(50);
									twist(50);
								}
								if (face5[53] != 53) {
									twist(51);
									while (face5[59] != 53) {
										twist_massiv({ 61,11,60,10 });
									}

									twist(50);
								}
								if (face5[57] != 57) {
									twist(50);
									while (face5[59] != 57) {
										twist_massiv({ 61,11,60,10 });
									}
									twist(51);
								}
							}
						}
					}
				}


			
	    }
		cout << "\nEnd assembling: Last corners\n";
	}
};

int main() {

	setlocale(LC_ALL, "ru");

	cub().stir(10000);
	
	cub().white_cross();
	cub().f1l();
	cub().f2l();
	cub().yellov_cross();
	cub().last_corners();
	cub().print();
	
	cout << ::count_twist - 10000;
}