#include "List.h"

//тест
bool is_test(const string& file_name_input, const string& file_name_output); 
//проверка результатов программы
bool is_check_result(const string& file_name_output, const int most, const int least, const int closest_to_NULL);

//поиск наибольшее значение
int find_most(const List& value);
//поиск наименьшее значение
int find_least(const List& value);
//поиск числа которое наиболее близкое к 0
int find_closest_to_NULL(const List& value);

//запуск всех тестов
int main()
{
    const int n_test = 3;
    const int n_under_tests = 2;

    string tests[n_test][n_under_tests] = { {"test_passed_1/input.txt", "test_passed_1/output.txt"}, 
                                            {"test_passed_2/input.txt", "test_passed_2/output.txt"},
                                            {"test_fail/input.txt", "test_fail/output.txt"} };
    int i_test;

    try
    {
        for (i_test = 0; i_test < n_test; i_test++)
        {
            cout << endl << "----------test" << i_test+1 << " begin----------" << endl;

            if (is_test(tests[i_test][0], tests[i_test][1]))
                cout << endl << "----------test" << i_test+1 << " passed----------" << endl;
            else
                cout << endl << "----------test" << i_test+1 << " failed----------" << endl;
        }
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
        cout << endl << "----------test" << i_test+1 << " failed----------" << endl;
    }


    return 0;
}

bool is_test(const string& file_name_input, const string& file_name_output)
{
    int most;
    int least;
    int closest_to_NULL;
    List value(file_name_input);
    
    if (!value.empty())
        cout << value.is_string() << endl;
    else 
        throw std::invalid_argument("list = []");

    most  = find_most(value); 
    cout << "most = " << most << endl;

    least = find_least(value);
    cout << "least = " << least << endl;

    closest_to_NULL = find_closest_to_NULL(value);
    cout <<  "closest_to_NULL = " << closest_to_NULL << endl;

    return is_check_result(file_name_output, most, least, closest_to_NULL);
}

bool is_check_result(const string& file_name_output, const int most, const int least, const int closest_to_NULL)
{
    std::ifstream f(file_name_output);
    
    if (f.is_open() && !f.eof())
    {   
        int _most, _least, _closest_to_NULL;
        f >> _most >> _least >> _closest_to_NULL;

        f.close();
        return (_most == most) && (_least == least) && (_closest_to_NULL == closest_to_NULL);
    }

    throw std::invalid_argument("File didnt open(" + file_name_output + ")");
}

int find_most(const List& value) 
{ 
    return *value.end(); 
}

int find_least(const List& value)
{ 
    return *value.begin(); 
}

int find_closest_to_NULL(const List& value)
{
    List::iterator it = value.begin();
    int cur_dif = abs(*it - 0);
    int closest_to_NULL = *it;

    for (++it; it != value.end(); ++it) 
    {
        if (abs(*it - 0) < cur_dif)
        {
            cur_dif = abs(*it - 0);
            closest_to_NULL = *it;
        }
    }

    return closest_to_NULL;
}