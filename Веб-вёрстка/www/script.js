menu = document.querySelector('.list_menu');
lines = document.querySelector('.menu__lines');

function toggleMenu() {
    menu.classList.toggle('hidden');
}

lines.addEventListener('click', toggleMenu);
