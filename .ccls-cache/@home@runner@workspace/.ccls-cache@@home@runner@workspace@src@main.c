#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_palindrome(int num){
	int origianl = num;
	int reverse = 0;
	while(num > 0){
		reverse = reverse * 10 + num % 10;
		num /= 10;
	}
	return reverse == origianl;
}

int count_palindromes(int *arr, int n){
	int count = 0;
	for(int i = 0; i < n; i++){
		if(is_palindrome(arr[i])){
			count++;
		}
	}
	return count;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Использование: %s <размер массива>\n", argv[0]);
		return 1;
	}

	int n = atoi(argv[1]);
	if (n <= 0) {
		printf("Размер массива должен быть положительным числом.\n");
		return 1;
	}

	srand(time(NULL));

	int *arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) {
			printf("Ошибка выделения памяти.\n");
			return 1;
	}

	for (int i = 0; i < n; i++) {
			arr[i] = rand() % 1000 + 1;
	}

	printf("Исходный массив:\n");
	for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
	}
	printf("\n");

	int palindrome_count = count_palindromes(arr, n);
	printf("Количество чисел-палиндромов: %d\n", palindrome_count);

	free(arr);
	
	return 0;
}
