#include <iostream>

//"Быстрая сортировка"

namespace std {
	int partition(int arr[], int low, int high) {
		int pivot = arr[high];
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++) {
			if (arr[j] <= pivot) {
				i++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		int temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;

		return (i + 1);
	}

	void quickSort(int arr[], int low, int high) {
		if (low < high) {
			int pi = partition(arr, low, high);

			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}

	void quickSort(int arr[], int size) {
		quickSort(arr, 0, size - 1);
	}
}

int main() {
	using namespace std;
	setlocale(0, "ru");
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	quickSort(arr, n);

	cout << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}

//"Сортировка методом слияния"

#include <iostream>

namespace std {
	void merge(int arr[], int left, int mid, int right) {
		int n1 = mid - left + 1;
		int n2 = right - mid;
		int* L = new int[n1];
		int* R = new int[n2];
		for (int i = 0; i < n1; i++)
			L[i] = arr[left + i];
		for (int j = 0; j < n2; j++)
			R[j] = arr[mid + 1 + j];
		int i = 0, j = 0, k = left;
		while (i < n1 && j < n2) {
			if (L[i] <= R[j]) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}
		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}
		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
		delete[] L;
		delete[] R;
	}
	void mergeSort(int arr[], int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;

			mergeSort(arr, left, mid);
			mergeSort(arr, mid + 1, right);

			merge(arr, left, mid, right);
		}
	}
	void mergeSort(int arr[], int size) {
		mergeSort(arr, 0, size - 1);
	}
}

int main() {
	using namespace std;
	setlocale(0, "ru");
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	mergeSort(arr, n);

	cout << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}