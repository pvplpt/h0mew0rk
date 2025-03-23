class Board:
    def __init__(self):
        self.board = [' '] * 9

    def print_board(self):
        """Печатает текущее состояние игрового поля."""
        print("-------------")
        for i in range(0, 9, 3):
            print("|", self.board[i], "|", self.board[i+1], "|", self.board[i+2], "|")
            print("-------------")

    def make_move(self, move, player):
        """Делает ход на доске."""
        if 0 <= move <= 8 and self.board[move] == ' ':
            self.board[move] = player
            return True
        return False

    def is_full(self):
        """Проверяет, заполнено ли игровое поле."""
        return all(cell != ' ' for cell in self.board)

    def check_win(self, player):
        """Проверяет, выиграл ли игрок."""
        win_combinations = [
            [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Горизонтали
            [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Вертикали
            [0, 4, 8], [2, 4, 6]             # Диагонали
        ]
        for combo in win_combinations:
            if all(self.board[i] == player for i in combo):
                return True
        return False


class Player:
    def __init__(self, symbol):
        self.symbol = symbol

    def get_move(self):
        """Получает ход от игрока."""
        while True:
            try:
                move = int(input(f"Игрок {self.symbol}, введите номер клетки (1-9): ")) - 1
                return move
            except ValueError:
                print("Неверный ввод. Попробуйте ещё раз.")


class Game:
    def __init__(self):
        self.board = Board()
        self.player_x = Player('X')
        self.player_o = Player('O')
        self.current_player = self.player_x

    def play(self):
        """Основная функция игры."""
        while True:
            self.board.print_board()
            move = self.current_player.get_move()

            if self.board.make_move(move, self.current_player.symbol):
                if self.board.check_win(self.current_player.symbol):
                    self.board.print_board()
                    print(f"Игрок {self.current_player.symbol} победил!")
                    break
                elif self.board.is_full():
                    self.board.print_board()
                    print("Ничья!")
                    break
                else:
                    self.current_player = self.player_o if self.current_player == self.player_x else self.player_x
            else:
                print("Неверный ход. Попробуйте ещё раз.")


if __name__ == "__main__":
    game = Game()
    game.play()