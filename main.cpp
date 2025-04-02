#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <tuple>

std::tuple<Matrix, Matrix> read_matrix_from_file(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    std::size_t N;
    file >> N;
    std::vector<std::vector<int>> matrix_data1(N, std::vector<int>(N));
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            file >> matrix_data1[i][j];
        }
    }

    Matrix matrix1(matrix_data1);
    std::vector<std::vector<int>> matrix_data2(N, std::vector<int>(N));

    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            file >> matrix_data2[i][j];
        }
    }

    Matrix matrix2(matrix_data2);
    return std::make_tuple(matrix1, matrix2);
}


void print_menu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add Matrices\n";
    std::cout << "2. Multiply Matrices\n";
    std::cout << "3. Sum of Diagonals\n";
    std::cout << "4. Swap Rows\n";
    std::cout << "5. Swap Columns\n";
    std::cout << "6. Update Value\n";
    std::cout << "7. Exit\n";
}

int main() {
    std::string filename;
    
    std::cout << "Enter the name of the file: ";
    std::cin >> filename;

    auto [matrix1, matrix2] = read_matrix_from_file(filename);

    std::cout << "Matrix 1:\n";
    matrix1.print_matrix();
    std::cout << "\nMatrix 2:\n";
    matrix2.print_matrix();

    int choice;
    do {
        print_menu();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Matrix summed_matrix = matrix1 + matrix2;
                std::cout << "Matrix 1 + Matrix 2:\n";
                summed_matrix.print_matrix();
                break;
            }
            case 2: {
                Matrix product_matrix = matrix1 * matrix2;
                std::cout << "Matrix 1 * Matrix 2:\n";
                product_matrix.print_matrix();
                break;
            }
            case 3: {
                std::cout << "Enter a matrix to calculate the sum of diagonals (1 or 2): ";
                std::cin >> choice;
                if (choice == 1) {
                    std::cout << "Sum of main diagonal: " << matrix1.sum_diagonal_major() << "\n";
                    std::cout << "Sum of secondary diagonal: " << matrix1.sum_diagonal_minor() << "\n";
                } else if (choice == 2) {
                    std::cout << "Sum of main diagonal: " << matrix2.sum_diagonal_major() << "\n";
                    std::cout << "Sum of secondary diagonal: " << matrix2.sum_diagonal_minor() << "\n";
                }
                break;
            }
            case 4: {
                std::size_t row1, row2;
                std::cout << "Enter a matrix to swap rows on (1 or 2): ";
                std::cin >> choice;
                std::cout << "Enter row indices to swap (space separated): ";
                std::cin >> row1 >> row2;
                if (row1 >= 0 && row2 >= 0 && row1 < matrix1.get_size() && row2 < matrix1.get_size()) {
                    if (choice == 1) {
                    matrix1.swap_rows(row1, row2);
                    matrix1.print_matrix();
                } else if (choice == 2) {
                    matrix2.swap_rows(row1, row2);
                    matrix2.print_matrix();
                }
                break;
                } else {
                    std::cout << "Invalid row indices. Please try again.\n";
                    continue;
                }
            }
            case 5: {
                std::size_t col1, col2;
                std::cout << "Enter a matrix to swap columns on (1 or 2): ";
                std::cin >> choice;
                std::cout << "Enter column indices to swap (space separated): ";
                std::cin >> col1 >> col2;
                if (col1 >= 0 && col2 >= 0 && col1 < matrix1.get_size() && col2 < matrix1.get_size()) {
                    if (choice == 1) {
                    matrix1.swap_cols(col1, col2);
                    matrix1.print_matrix();
                } else if (choice == 2) {
                    matrix2.swap_cols(col1, col2);
                    matrix2.print_matrix();
                }
                break;
                } else {
                    std::cout << "Invalid column indices. Please try again.\n";
                    continue;
                }
            }
            case 6: {
                std::size_t row, col;
                int value;
                std::cout << "Enter a matrix to update a value in (1 or 2): ";
                std::cin >> choice;
                std::cout << "Enter row, column, and new value (space separated): ";
                std::cin >> row >> col >> value;
                if (row >= 0 && col >= 0 && row < matrix1.get_size() && col < matrix1.get_size()) {
                    if (choice == 1){
                    matrix1.set_value(row, col, value);
                    matrix1.print_matrix();
                } else if (choice == 2){
                    matrix2.set_value(row, col, value);
                    matrix2.print_matrix();
                }
                break;
                } else {
                    std::cout << "Invalid row or column index. Please try again.\n";
                    continue;
                }
            }
            case 7:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

