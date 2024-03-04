// main.cpp

#include <iostream>
#include <array> // статический массив
#include <vector> // динамический массив
#include <deque> // связанный список массивов с произвольным доступом

// коллекции языка С++
// требования к вложенным типам и особенности работы
// статический массив
// динамический массив
// deque спецконтейнер хранится по 8 кусочков
// манера работы с памятью:
// vector при необходимости добавить память, то
// vector увеличивает свой размер в 1.2-2 раза

// deque при неоходимости добавить блок,
// то память увеличивается на один блок.

// deque лояльно относится к добавлению и удалению элементов в середине памяти,
// в остальные точки добавление и удаление происходит одинаково по времени

// vector хорошо работает при добавлении в конец данных

// deque - использование -> частое удаление и добавление данныйх в произвольное месть

// хороший класс для работы коллекций - необходимые методы которые необходимо описать
class DemoGood {
public:
	// конструктор по умолчанию
	DemoGood() {
		std::cout << this << " create by default constructor\n";
	}

	// параметрический конструктор
	DemoGood(int a, bool b) {
		std::cout << this << " create by parametric constructor\n";
	}

	// конструктор копирования
	DemoGood(const DemoGood& other) {
		std::cout << this << " create by copy constructor\n";
		std::cout << "from " << &other << " object\n";
	}

	// деструктор
	~DemoGood() {
		std::cout << this << " destroyed\n";
	}

};


// плохой класс для работы коллекций - нет необходимых методов которые необходимо описать
class DemoBad {
public:
	// конструктор по умолчанию
	DemoBad() = delete; // запрет компилятору  реализации конструктора по умолчанию

	// параметрический конструктор
	DemoBad(int a, bool b) = delete;
	/*{
		std::cout << this << " create by parametric constructor\n";
	}*/

	// конструктор копирования
	DemoBad(const DemoGood& other) {
		std::cout << this << " create by copy constructor\n";
		std::cout << "from " << &other << " object\n";
	}

	// деструктор
	~DemoBad() {
		std::cout << this << " destroyed\n";
	}

};

int main() {

	/*DemoGood arr[10];
	std::cout << std::size(arr) << std::endl;*/

	std::array<DemoGood,10> arrST;

	// статический массив выделяет место под весь необходимые объем памяти и заполняет
	// его объектами созданными конструктором по умолчанию

	std::vector<DemoGood> arrDin;
	arrDin.reserve(10);
	// вектор не выделяет памяти если ему не сказать, но может отдельной
	// командой зарезервировать место не создавая объекты

	std::deque<DemoGood> arrDeque(10);
	// деке как и вектору можно при создании сказать на какое
	// количество элементов она создана. При этом будет создано
	// необходимое количество болванок с помощью конструктора по умолчанию

	//std::array<DemoBad, 10> arrST2{
	//							DemoBad(1,true),
	//							DemoBad(2,true),
	//							DemoBad(3,true), 
	//							DemoBad(4,true), 
	//							DemoBad(5,true), 
	//							DemoBad(6,true), 
	//							DemoBad(7,true), 
	//							DemoBad(8,true), 
	//							DemoBad(9,true), 
	//							DemoBad(0,true), 
	//// в случае отсутствия конструктора по умолчанию для стандартных коллекций, которым требуется сразу быть заполненными какими-то
	//// объектами, остается вариант конструктора через список инициализации.
	//// именно такой список мы отправили в {}					
	//};

	// std::vector<DemoBad> nArr(arrST2.begin(),arrST2.end());


	arrDin.push_back(DemoGood(0,true)); // insert методы работают за счет конструкторов копирования
	arrDin.emplace_back(0, true); //  emplace методы работают за счет конструкторов с параметрами

	std::vector<DemoBad> nArr;

	/*nArr.push_back(DemoBad(0, true));
	nArr.emplace_back(0, true);*/
	// так как конструктор с параметрами не доступен методы категории emplace будут вызывать ошибки сборки с указанием
	// на невозможность обращения к данному конструктору


	std::cout << "=============================================================\n";
	std::vector<DemoGood> example;

	for (int i = 0; i < 17; i++) {
		//example.emplace_back(i, bool(i % 2));
		example.push_back(DemoGood(i, bool(i % 2)));
	}


	return 0;
}