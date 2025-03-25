def binary_search(integer_array, number):
    left, right = 0, len(integer_array) - 1
    while left <= right:
        mid = (left + right) // 2
        if integer_array[mid] == number:
            return mid
        elif integer_array[mid] < number:
            left = mid + 1
        else:
            right = mid - 1
    return -1


if __name__ == "__main__":
    array = [0, 1, 2, 3, 5, 8, 13, 21, 34, 55]
    number = 21
    print(f"Искомый индекс {binary_search(array, number)}")

