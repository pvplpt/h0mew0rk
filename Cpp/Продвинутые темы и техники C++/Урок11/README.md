## Урок 11. Парадигмы ООП

### В практической работе есть:

Обязательные задачи помогут проверить, как вы усвоили материал модуля. Их нужно сдать на проверку куратору.
Дополнительные задачи подойдут тем, кто хочет ещё немного потренироваться, решая задачки по программированию. Вы также можете отправлять их на проверку и получать обратную связь куратора, хотя это необязательно.

### Цели практической работы

• Закрепить навыки работы с классами C++.  
• Понять прикладной характер принципов ООП.  
• Освоить использование виртуальных функций для создания интерфейсов.

### Что входит в работу

Обязательные задачи:

1. Задача 1. Суперпёс.  
   Дополнительные задачи:
2. Задача 2. Интерфейс Shape (по желанию).

### Задача 1. Суперпёс

Возьмём решение из видео. Все наши животные могут мяукать и гавкать, то есть издавать звуки в соответствии со своим классом. Но что, если нужно добавить им новое поведение, например, научить плавать или стоять на задних лапах. Рассмотрим класс Dog: все собаки умеют лаять и бегать, а некоторые собаки умеют хорошо плавать. Чтобы добавить эти качества классу Dog, мы можем создать ещё один класс «плавающих» животных и наследовать от него наш класс. Но что, если не все собаки умеют хорошо плавать, а некоторые из них совсем не умеют плавать.Наша задача — построить класс Dog таким образом, чтобы к его объектам можно было выборочно добавлять новые умения, но при этом не менять поведение основного класса. Список умений будет вызываться с помощью метода show_talents().

#### Что нужно сделать

1. Создайте класс Dog, к которому можно добавлять новые способности.
2. Создайте абстрактный класс «Талант» (Talent), от которого будут наследоваться все добавляемые способности. Пока таких способностей три: умение плавать (Swimming), умение танцевать (Dancing), умение считать (Counting), но можете добавить и другие.
3. Создайте у класса Dog метод show_talents() для показа всех способностей, которыми обладает собака.

#### Требования к реализации

Класс Talent должен быть абстрактным. Это значит, что объекты такого класса мы создать не сможем, так как одна из его функций объявлена как «чисто» виртуальная (pure virtual).  
Каждая способность, наследуемая от абстрактного класса Talent, должна быть представлена в виде отдельного класса.  
Пример выполнения  
Создаём собаку с именем Steve:  
Dog dog1("Steve")
Добавляем ей умение танцевать и плавать.  
Если мы сделаем запрос умений show_talents(), то на экран будет выведено:

```
This is Steve and it has some talents:
It can “Dance”
It can “Swim”
```

#### Советы и рекомендации

• Для хранения способностей можно использовать вектор.  
• Для создания абстрактного класса рекомендуем пересмотреть видео, где функция voice в классе Animal была объявлена «чисто» виртуальной. Это поможет в выполнении задания.

#### Что оценивается

• Класс Talent является абстрактным.  
• Все способности являются классами и наследуются от класса Talent.  
• Класс Dog не наследуется от класса Talent.  
• При ответе на запрос show_talents в консоли должны быть последовательно написаны все умения, которыми обладает собака.

### Задача 2. Интерфейс Shape (дополнительное задание)

У вас есть набор классов различных геометрических фигур: круг(Circle), прямоугольник(Rectangle) и треугольник(Triangle), которые наследуются от общего класса геометрическая фигура (Shape). Каждый из этих классов имеет методы подсчёта площади, описывающего прямоугольника и взятия типа. Также есть общая функция printParams которая по переданному ей указателю на объект типа геометрическая фигура выводит на экран тип фигуры.

#### Что нужно сделать

Создайте интерфейс Shape (фигуру), который предоставляет следующие методы:  
— virtual double square() = 0; — возвращает площадь конкретной фигуры;  
— virtual BoundingBoxDimensions dimensions() = 0; — размеры описывающего прямоугольника;  
BoundingBoxDimensions — простая структура, которая содержит ширину и высоту;  
— virtual std::string type() = 0; — название конкретного типа, например, вернуть строку Triangle для класса Triangle;  
void printParams(Shape \*shape) — сюда можно будет передавать любые фигуры:

```
{
std::cout <<"Type: " << shape->type() << std::endl;
}
```

комбинация virtual … = 0; — создаёт чисто виртуальный метод. Это означает, что такой метод обязательно должен быть переопредёлен в классе-наследнике. Если программист пронаследует свой класс от такого интерфейса, то компилятор будет ругаться на отсутствие методов, описанных как virtual … = 0. То есть программист будет вынужден добавить такие методы в свой класс, чтобы создать объект такого типа.
….  
Создайте классы-наследники Shape: Circle, Rectangle и Triangle.  
У каждого из классов будет разный набор полей: у треугольника будут три стороны в виде переменных double, у круга — радиус, а у прямоугольника — длина и ширина. Так как все они наследуются от Shape, в каждом из классов следует реализовать методы нахождения размерности, площади и метод, возвращающий название типа.  
Площадь треугольника при известных длинах сторон находится при помощи формулы Герона:
sqrt(p _ (p - a) _ (p - b) _ (p - c)), где p — полупериметр.  
Размеры описывающего прямоугольника для треугольника находятся по похожей формуле — сначала находим радиус описанной окружности:  
a _ b _ c / (4 _ sqrt(p*(p - a)*(p - b)\*(p - c))), где р — снова полупериметр.
Затем умножаем его на два и получаем сторону квадрата, в который помещён треугольник.
В функции main вызовите printParams со всеми типами, которые вы создали.

```
Пример

Triangle t(3,4,5);
printParams(&t);

Вывод

Type: Triangle
Square: 6
Width: 5
Height: 5
```

#### Что оценивается

• Приложение выводит в консоль сообщения о типе фигуры, которые соответствуют действительности.  
• Функция принимает корректные типы данных. Тип возвращаемого значения — void.  
• Решение выполнено через создание наследников от интерфейса Shape.  
• Сигнатура функции void — printParams (Shape \*shape). Любая другая некорректна.

### Как отправить работу на проверку

Отправьте ссылку на repl.it или файл .срр с решением через форму ниже.  
Отправьте все .cpp- и .h-файлы (в которых вы описали фигуры), main.cpp и CMakeLists.txt (который описывает проект). Желательно каждую фигуру (класс-наследник shape) описывать в отдельном файле.
