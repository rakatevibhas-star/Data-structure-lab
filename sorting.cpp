#include <iostream>
using namespace std;
int main() {
    int a[100], n = 0, ch;
    char x;
    do {
        cout << "\n1. Create Array";
        cout << "\n2. Bubble Sort";
        cout << "\n3. Insertion Sort";
        cout << "\n4. Quick Sort";
        cout << "\n5. Merge Sort";
        cout << "\n6. Selection Sort";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1:
                cout << "Enter size of array: ";
                cin >> n;
                cout << "Enter elements: ";
                for(int i = 0; i < n; i++)
                    cin >> a[i];
                break;
            case 2: 
                for(int i = 0; i < n - 1; i++) {
                    for(int j = 0; j < n - i - 1; j++) {
                        if(a[j] > a[j + 1]) {
                            int t = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = t;
                        }
                    }
                }
                cout << "Sorted array: ";
                for(int i = 0; i < n; i++) cout << a[i] << " ";
                break;
            case 3: 
                for(int i = 1; i < n; i++) {
                    int key = a[i];
                    int j = i - 1;
                    while(j >= 0 && a[j] > key) {
                        a[j + 1] = a[j];
                        j--;
                    }
                    a[j + 1] = key;
                }
                cout << "Sorted array: ";
                for(int i = 0; i < n; i++) cout << a[i] << " ";
                break;
            case 4: 
            {
                int stack[100], top = -1;
                stack[++top] = 0;
                stack[++top] = n - 1;
                while(top >= 0) {
                    int high = stack[top--];
                    int low = stack[top--];
                    int pivot = a[high];
                    int i = low - 1;
                    for(int j = low; j < high; j++) {
                        if(a[j] < pivot) {
                            i++;
                            int t = a[i];
                            a[i] = a[j];
                            a[j] = t;
                        }
                    }
                    int t = a[i + 1];
                    a[i + 1] = a[high];
                    a[high] = t;

                    int p = i + 1;

                    if(p - 1 > low) {
                        stack[++top] = low;
                        stack[++top] = p - 1;
                    }
                    if(p + 1 < high) {
                        stack[++top] = p + 1;
                        stack[++top] = high;
                    }
                }
                cout << "Sorted array: ";
                for(int i = 0; i < n; i++) cout << a[i] << " ";
                break;
            }
            case 5: 
            {
                for(int curr = 1; curr < n; curr *= 2) {
                    for(int left = 0; left < n - 1; left += 2 * curr) {
                        int mid = min(left + curr - 1, n - 1);
                        int right = min(left + 2 * curr - 1, n - 1);
                        int temp[100];
                        int i = left, j = mid + 1, k = left;
                        while(i <= mid && j <= right) {
                            if(a[i] <= a[j])
                                temp[k++] = a[i++];
                            else
                                temp[k++] = a[j++];
                        }
                        while(i <= mid)
                            temp[k++] = a[i++];

                        while(j <= right)
                            temp[k++] = a[j++];

                        for(int p = left; p <= right; p++)
                            a[p] = temp[p];
                    }
                }
                cout << "Sorted array: ";
                for(int i = 0; i < n; i++) cout << a[i] << " ";
                break;
            }
            case 6: 
                for(int i = 0; i < n - 1; i++) {
                    int min = i;
                    for(int j = i + 1; j < n; j++) {
                        if(a[j] < a[min])
                            min = j;
                    }
                    int t = a[i];
                    a[i] = a[min];
                    a[min] = t;
                }
                cout << "Sorted array: ";
                for(int i = 0; i < n; i++) cout << a[i] << " ";
                break;

            default:
                cout << "Invalid choice!";
        }
        cout << "\nDo you want to continue (y/n): ";
        cin >> x;
    } while(x == 'y' || x == 'Y');
    return 0;
}