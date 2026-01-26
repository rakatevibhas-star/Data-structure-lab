#include <iostream>
using namespace std;

int main() {
    int i, j, k;
    int ch;
    char x;
    int a[3][3], b[3][3];
    int sum[3][3], sub[3][3], trans[3][3];

    do {
        cout << "\n1. Create Matrices";
        cout << "\n2. Display Matrices";
        cout << "\n3. Addition";
        cout << "\n4. Subtraction";
        cout << "\n5. Transpose of Matrix ";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {

            case 1:
                cout << "Enter elements of Matrix A:\n";
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        cin >> a[i][j];
                    }
                }

                cout << "Enter elements of Matrix B:\n";
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        cin >> b[i][j];
                    }
                }
                break;

            case 2:
                cout << "\nMatrix A:\n";
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        cout << a[i][j] << " ";
                    }
                    cout << endl;
                }

                cout << "\nMatrix B:\n";
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        cout << b[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 3:
                cout << "\nAddition of matrices:\n";
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        sum[i][j] = a[i][j] + b[i][j];
                        cout << sum[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 4:
                cout << "\nSubtraction of matrices:\n";
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        sub[i][j] = a[i][j] - b[i][j];
                        cout << sub[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 5:
                cout << "\nTranspose of Matrix A:\n";
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        trans[j][i] = a[i][j];
                    }
                }

                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        cout << trans[i][j] << " ";
                    }
                    cout << endl;
                }

                cout << "\nTranspose of Matrix B:\n";
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        trans[j][i] = b[i][j];
                    }
                }

                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        cout << trans[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            default:
                cout << "Invalid choice!";
        }

        cout << "\nDo you want to continue : ";
        cin >> x;

    } while (x == 'y' || x == 'Y');

    return 0;
}