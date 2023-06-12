// Основное задание
//
// 1) Создать страницу, которая спрашивает имя у пользователя и 
//    выводит его с помощью функции.

let name = prompt("Как Вас зовут?", "Имя");
alert(`Привет, ${name}`);

// 2) Перепишите код, используя конструкцию switch-case, 
//    запрашивая возраст пользователя через диалоговое окно.

let age = +prompt("Введите Ваш возраст", "45");
switch (age) {
    case 18:
        alert("Вы совершеннолетний, все можно!");
        break;
    case 10:
        alert("Вам надо учить уроки!");
        break;
    case 30:
        alert("Ложитесь спать, завтра на работу!");
        break;
    default:
        alert("Мы не знаем что Вам делать!");
        break;
}

// Доп задание
//
// 1) Сделать так, чтобы при нажатии на кнопку 
//    менялся цвет и текст элемента < p > 

let newText = "Цвет и текст элемента <p> поменялся"

function clickButton() {
    let el = document.getElementById('svetotext');    
    el.classList.toggle('active');
    let tmp = el.textContent;
    el.textContent = newText;
    newText = tmp;
}

let bt = document.getElementById('btn1');
bt.addEventListener('click', clickButton);


