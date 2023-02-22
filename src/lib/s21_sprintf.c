#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  // главная функция, где всё запускается
  str[0] = '\0';
  const char *format1 = S21_NULL;
  format1 = format;
  va_list ap;
  va_start(ap, format);
  // перебираем строку формат до конца
  while (*format1 != '\0') {
    struct S21_sprintf_param cure_param;
    struct_init(&cure_param);
    // присваивание структуре с параметрами начальных значений
    char preceding_str[1024] = "\0";  // Строка, в которую помещается всё, что
                                      // идёт до процента
    char used_str[1024] = "\0";  // строка, которую надо будет распарсить
    // присваиваем указателю формат указатель на последний символ, который
    // обработали в парсере
    format1 = parser_used_preceding_str(format1, preceding_str, used_str);
    // получаем 2 строки 1.та, которая идёт до % 2.строка формата
    //%*спецификатор
    structuring_str(preceding_str, used_str, &cure_param);
    // распаршивание строки и заполнение структуры
    sprintf_logic(&ap, cure_param, str);
    // обработка параметров и составление конечной строки
  }
  va_end(ap);
  return s21_strlen(str);
}

void sprintf_logic(va_list *ap, struct S21_sprintf_param cure_param,
                   char *str) {
  // обработка параметров и составление конечной строки
  if (cure_param.specifier == 'c') {
    c_logic(ap, cure_param, str);
  }
  if (cure_param.specifier == 'd' || cure_param.specifier == 'i') {
    di_logic(ap, cure_param, str);
  }
  if (cure_param.specifier == 'u') {
    u_logic(ap, cure_param, str);
  }
  if (cure_param.specifier == 'f') {
    f_logic(ap, cure_param, str);
  }
  if (cure_param.specifier == 's') {
    s_logic(ap, cure_param, str);
  }

  if (cure_param.specifier == '\0') {
    s21_strcat(str, cure_param.preceding_str);
  }
}

void di_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str) {
  char base_int_str[512] = "\0";  // строка, куда добавляется само число
                                  // переведённое в строку и точность
  char base_str_with_params[512] = "\0";  // строка со всеми параметрами
  if (cure_param.length != '\0') {
    // считывание аргумента в зависимости от длины(От этого засисит тип
    // переменной)
    if (cure_param.length == 'l') {
      long int number = va_arg(*ap, long int);
      base_int_to_str(base_int_str, number, cure_param);
      // получение строки без знака
      base_int_to_str_with_flags(base_int_str, base_str_with_params, cure_param,
                                 number);
      // получение строки со всеми параметрами
    }
    if (cure_param.length == 'h') {
      short int number = (short int)va_arg(*ap, int);
      base_int_to_str(base_int_str, number, cure_param);
      // получение строки без знака
      base_int_to_str_with_flags(base_int_str, base_str_with_params, cure_param,
                                 number);
      // получение строки со всеми параметрами
    }
  } else {
    int number = va_arg(*ap, int);
    base_int_to_str(base_int_str, number, cure_param);
    // получение строки без знака
    base_int_to_str_with_flags(base_int_str, base_str_with_params, cure_param,
                               number);
    // получение строки со всеми параметрами
  }
  s21_strcat(str, cure_param.preceding_str);
  s21_strcat(str, base_str_with_params);
}

void c_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str) {
  char c = (char)va_arg(*ap, int);
  s21_strcat(str, cure_param.preceding_str);
  c_to_string(str, cure_param, c);
}

void u_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str) {
  char base_int_str[512] = "\0";  // строка, куда добавляется само число
                                  // переведённое в строку и точность
  char base_str_with_params[512] = "\0";  // строка со всеми параметрами
  if (cure_param.length != '\0') {
    // считывание аргумента в зависимости от длины(От этого засисит тип
    // переменной)
    if (cure_param.length == 'l') {
      long unsigned int number = va_arg(*ap, long unsigned int);
      base_int_to_str(base_int_str, number, cure_param);
      // получение строки без знака
      base_int_to_str_with_flags(base_int_str, base_str_with_params, cure_param,
                                 number);
      // получение строки со всеми параметрами
    }
    if (cure_param.length == 'h') {
      short unsigned int number = (unsigned short int)va_arg(*ap, int);
      base_int_to_str(base_int_str, number, cure_param);
      // получение строки без знака
      base_int_to_str_with_flags(base_int_str, base_str_with_params, cure_param,
                                 number);
      // получение строки со всеми параметрами
    }
  } else {
    int unsigned number = va_arg(*ap, unsigned int);
    base_int_to_str(base_int_str, number, cure_param);
    // получение строки без знака
    base_int_to_str_with_flags(base_int_str, base_str_with_params, cure_param,
                               number);
    // получение строки со всеми параметрами
  }
  s21_strcat(str, cure_param.preceding_str);
  s21_strcat(str, base_str_with_params);
}

void f_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str) {
  char base_float_str[512] = "\0";
  // сюда вставляется само число + точность + знак
  char base_float_str_with_params[512] = "\0";
  // Здесь все вместе со всеми параметрами
  double number = va_arg(*ap, double);
  if (cure_param.precision == -400) {  // ставим дефолтную точность
    cure_param.precision = 6;
  }
  set_base_float_str_with_param(base_float_str_with_params, base_float_str,
                                number, cure_param);
  s21_strcat(str, cure_param.preceding_str);
  s21_strcat(str, base_float_str_with_params);
}

void s_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str) {
  char *input_str = va_arg(*ap, char *);
  // строка, которую мы получаем из аргументов
  char base_string_str_with_params[2048] = "\0";
  // строка со всеми параметрами
  set_string_with_params_str(input_str, base_string_str_with_params,
                             cure_param);
  s21_strcat(str, cure_param.preceding_str);
  s21_strcat(str, base_string_str_with_params);
}

void structuring_str(char *preceding_str, char *used_str,
                     struct S21_sprintf_param *cure_param) {
  // распаршивание строки и заполнение структуры с параметрами
  const char specifiers_str[7] = "cdifsu\0";
  cure_param->preceding_str = preceding_str;
  int used_str_index = 0;
  int used_str_len = s21_strlen(used_str);
  if (s21_strchr(specifiers_str, used_str[used_str_len - 1])) {
    // проверяем, что в конце строки спецификатор и добавляем его
    cure_param->specifier = used_str[used_str_len - 1];
    used_str[used_str_len - 1] = '\0';
    if (used_str_len == 1) {
      cure_param->precision = -400;
      cure_param->width = -400;
    }
  }
  while (used_str[used_str_index] != '\0') {
    // перебираем строку до конца(каждый метод изменяет итератор)
    int set_flag_result =
        set_flags(used_str[used_str_index], cure_param, &used_str_index);
    int set_precision_result =
        set_precision(used_str, &used_str_index, cure_param);
    int set_width_result = set_width(used_str, &used_str_index, cure_param);
    int set_length_result = set_length(used_str, &used_str_index, cure_param);
    int is_changed = set_flag_result + set_precision_result + set_width_result +
                     set_length_result;
    if (is_changed == 0) {
      // если итератор не изменён в функциях, то прибавляем его
      used_str_index++;
    }
  }
}

void c_to_string(char *str, struct S21_sprintf_param cure_param, char c) {
  int str_len = s21_strlen(str);
  if (cure_param.width != -400) {
    // добавшение ширины
    if (s21_strchr(cure_param.flag, '-')) {
      str[str_len + 0] = c;
      // заполнение строки пробелами
      for (int i = 1; i < cure_param.width; i++) {
        str[str_len + i] = ' ';
      }
    } else {
      // заполнение строки пробелами
      for (int i = 0; i < cure_param.width - 1; i++) {
        str[str_len + i] = ' ';
      }
      str[str_len + cure_param.width - 1] = c;
    }
    str[str_len + cure_param.width] = '\0';
  } else {
    // просто добавление символа в итоговую строку
    int len = s21_strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
  }
}

const char *parser_used_preceding_str(const char *format, char *preceding_str,
                                      char *used_str) {
  // получаем 2 строки 1.та, которая идёт до % 2.строка формата %*спецификатор
  int format_i = 0;  // итератор для строки формат
  int flag = 0;  // флаг, который означает, что мы встретили спецификатор
  int preceding_str_index = 0;  // итератор для строки до %
  int used_str_index = 0;  // итератор для строки %*спецификатор
  set_empty_str(preceding_str, used_str);
  int end_flag = 1;
  while (format[format_i] != '\0' && !flag) {
    // пробегаемся по строке пока не встретим пробел или спецификатор
    if (format[format_i] == '%' && format[format_i + 1] != '%') {
      is_not_closed_perc(end_flag, used_str, preceding_str, &used_str_index,
                         &preceding_str_index);
      preceding_str[preceding_str_index] = '\0';
      preceding_str_index++;
      end_flag = 0;
      format_i++;
      const char specifiers_str[8] = "cdifsu\0";  // список спецификаторов
      while (!s21_strchr(specifiers_str, format[format_i]) &&
             !(format[format_i] == '%')) {
        // пока не встречаем спецификатор или
        // другой % добавляем символы в
        used_str[used_str_index] = format[format_i];  // used_str
        format_i++;
        used_str_index++;
      }
      if (s21_strchr(specifiers_str, format[format_i])) {
        // если последний символ - спецификатор,добавляем его в used_str,
        // настраиваем параметры и завершаем строку
        end_flag = 1;
        flag = 1;
        used_str[used_str_index] = format[format_i];
        format_i++;
        used_str_index++;
        used_str[used_str_index] = '\0';
        used_str_index++;
      }
    } else {
      if (format[format_i] == '%' && format[format_i + 1] == '%') {
        preceding_str[preceding_str_index] = format[format_i];
        format_i += 2;
        preceding_str_index++;
      } else {
        preceding_str[preceding_str_index] = format[format_i];
        format_i++;
        preceding_str_index++;
      }
    }
  }
  set_end(preceding_str, preceding_str_index);
  set_end(used_str, used_str_index);
  return (format + format_i);
}

void is_not_closed_perc(int end_flag, char *used_str, char *preceding_str,
                        int *used_str_index, int *preceding_str_index) {
  if (end_flag == 0) {
    // Если у нас уже был %, который не закончился спецификатором, то всю
    // строку после % закидываем в preceding_str и used_str зануляем
    used_str[*used_str_index] = '\0';
    s21_strcat(preceding_str, used_str);
    *preceding_str_index = s21_strlen(preceding_str);
    used_str[0] = '\0';
    *used_str_index = 0;
  }
}

void set_end(char *preceding_str, int buffer_index) {
  if (preceding_str[buffer_index - 1] != '\0') {
    preceding_str[buffer_index] = '\0';
  }
}
void set_empty_str(char *preceding_str, char *used_str) {
  preceding_str[0] = '\0';
  used_str[0] = '\0';
}
int set_flags(char format, struct S21_sprintf_param *cure_param,
              int *used_str_index) {
  int result = 0;
  if (format == '+' || format == '-' || format == ' ') {
    char buffer[5] = "\0";
    buffer[0] = format;
    buffer[1] = '\0';
    s21_strcat(cure_param->flag, buffer);
    result = 1;
    (*used_str_index)++;
  }
  return result;
}
int set_precision(char *used_str, int *used_str_index,
                  struct S21_sprintf_param *cure_param) {
  int result = 0;
  if (cure_param->precision <= 0) {
    int precision = -1;
    if (used_str[*used_str_index] == '.') {
      (*used_str_index)++;
      result = 1;
      char presicion_str[256] = "\0";
      get_int_str(used_str, presicion_str, used_str_index);
      precision = char_to_int(presicion_str);
    }
    if (precision == -1) {
      cure_param->precision = -400;  // значение, если точность не указана
    } else {
      cure_param->precision = precision;
    }
  }
  return result;
}

void get_int_str(char *used_str, char *int_str, int *used_str_index) {
  // спаршиваем строку состоящую из цифр
  int iter = 0;
  while (used_str[*used_str_index] >= 48 && used_str[*used_str_index] <= 57) {
    int_str[iter] = used_str[*used_str_index];
    iter++;
    (*used_str_index)++;
  }
  int_str[iter] = '\0';
}
int char_to_int(char *int_str) {
  // переводим знаки цифровой строки в число
  int len = s21_strlen(int_str);
  int result = 0;
  for (int i = 0; i < len; i++) {
    if (*int_str == 49) {
      result += pow(10, len - 1 - i);
    }
    if (*int_str == 50) {
      result += 2 * pow(10, len - 1 - i);
    }
    if (*int_str == 51) {
      result += 3 * pow(10, len - 1 - i);
    }
    if (*int_str == 52) {
      result += 4 * pow(10, len - 1 - i);
    }
    if (*int_str == 53) {
      result += 5 * pow(10, len - 1 - i);
    }
    if (*int_str == 54) {
      result += 6 * pow(10, len - 1 - i);
    }
    if (*int_str == 55) {
      result += 7 * pow(10, len - 1 - i);
    }
    if (*int_str == 56) {
      result += 8 * pow(10, len - 1 - i);
    }
    if (*int_str == 57) {
      result += 9 * pow(10, len - 1 - i);
    }
    int_str++;
  }
  return result;
}
void struct_init(struct S21_sprintf_param *cure_param) {
  // присваивание структуре с параметрами начальных значений
  cure_param->flag[0] = '\0';
  cure_param->length = '\0';
  cure_param->precision = 0;
  cure_param->specifier = '\0';
  cure_param->width = 0;
  cure_param->preceding_str = S21_NULL;
}
int set_width(char *used_str, int *used_str_index,
              struct S21_sprintf_param *cure_param) {
  int result = 0;
  if (cure_param->width <= 0) {
    char width_str[1024] = "\0";
    int width = 0;
    if (used_str[*used_str_index] >= 48 && used_str[*used_str_index] <= 57) {
      get_int_str(used_str, width_str, used_str_index);
      width = char_to_int(width_str);
      result = 1;
    }
    if (width == 0) {
      cure_param->width = -400;  // значение, если ширина не указана
    } else {
      cure_param->width = width;
    }
  }
  return result;
}
int set_length(char *used_str, int *used_str_index,
               struct S21_sprintf_param *cure_param) {
  int result = 0;
  const char length_str[8] = "hlL\0";
  if (s21_strchr(length_str, used_str[*used_str_index])) {
    cure_param->length = used_str[*used_str_index];
    (*used_str_index)++;
    result = 1;
  }
  return result;
}

void base_int_to_str(char *str, long int number,
                     struct S21_sprintf_param cure_param) {
  // Получает на вход интовое число и в стр записывает его без знака
  int degree_of_ten = 0;
  int len = s21_strlen(str);
  int figure = 0;
  if (number < 0) {
    // делаем число положительным, иначе крашится
    number *= -1;
  }
  if (number == 0 &&
      (cure_param.precision != 0 || cure_param.specifier == 'f')) {
    str[0] = '0';
    str[1] = '\0';
    degree_of_ten++;
    degree_of_ten++;
  }
  len = s21_strlen(str);
  char figures[12] = "0123456789\0";
  // вычисляем последнюю цифру числа и добавляем ее в баффер(получается строка с
  // перевёрнутым числом)
  while (number % (long int)pow(10, degree_of_ten) != number) {
    figure = number % (long int)pow(10, degree_of_ten + 1) /
             (long int)pow(10, degree_of_ten);
    str[len + degree_of_ten] = figures[figure];
    degree_of_ten++;
  }
  str[len + degree_of_ten] = '\0';
  reverse_str(str);  // переворачиваем строку, чтобы получилось нормальное число
}
void reverse_str(char *str) {
  int len = s21_strlen(str);
  char buffer = '\0';
  for (int i = 0; i < len / 2; i++) {
    buffer = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = buffer;
  }
}

void base_int_to_str_with_flags(char *base_int_str, char *base_str_with_params,
                                struct S21_sprintf_param cure_param,
                                long int number) {
  // Заполняется base_str_with_params
  if (s21_strlen(cure_param.flag) != 0) {  // проверяем флаги
    char sign = '0';
    set_sign(&sign, number, cure_param);
    if (s21_strchr(cure_param.flag, '-')) {  // минус
      set_int_precision(cure_param.precision, base_int_str);
      // ставим точность в base_int_str
      if (sign != '0') {
        set_sign_base_int_str(sign, base_int_str);  // ставим минус в base_str
      }
      s21_strcat(base_str_with_params, base_int_str);
      set_precision_or_width_to_int_str(cure_param.width, base_int_str,
                                        base_str_with_params, ' ');
    } else {
      set_int_precision(cure_param.precision, base_int_str);
      // ставим точность в base_int_str
      if (sign != '0') {
        set_sign_base_int_str(sign, base_int_str);  // ставим знак в base_str
      }
      set_precision_or_width_to_int_str(cure_param.width, base_int_str,
                                        base_str_with_params, ' ');
      // ставим ширину в base_str_with_params
      s21_strcat(base_str_with_params, base_int_str);
      // соединяем base_str_with_params с base_int_str
    }
  } else {
    set_int_precision(cure_param.precision, base_int_str);
    // ставим точность в base_int_str
    if (number < 0) {
      set_sign_base_int_str('-', base_int_str);  // ставим знак в base_int_str
    }
    set_precision_or_width_to_int_str(cure_param.width, base_int_str,
                                      base_str_with_params, ' ');
    // ставим ширину в base_str_with_params
    s21_strcat(base_str_with_params, base_int_str);
    // соединяем base_str_with_params с base_int_str
  }
}
void set_sign(char *sign, long int number,
              struct S21_sprintf_param cure_param) {
  if (number < 0) {  // выбираем знак
    *sign = '-';
  } else {
    if (s21_strchr(cure_param.flag, '+')) {
      *sign = '+';
    } else {
      if (s21_strchr(cure_param.flag, ' ')) {
        *sign = ' ';
      }
    }
  }
}

void set_precision_or_width_to_int_str(
    int precision_or_weight,  // число,сколько символов надо добавить
    char *base_int_str,  // строка из числа без знака
    char *base_str_with_params,  // строка, куда добавляем всё, что нужно
    char sign) {  // знак, который надо добавить
  // Эта функция добавляет точность или ширину или любой другой символ в
  //  base_str_with_params
  int base_int_str_len = s21_strlen(base_int_str);
  if (precision_or_weight > base_int_str_len) {
    int with_flags_len = s21_strlen(
        base_str_with_params);  // длина базовой строки для добавления в конец
    for (int i = 0; i < precision_or_weight - base_int_str_len; i++) {
      base_str_with_params[with_flags_len + i] = sign;
    }
    base_str_with_params[with_flags_len + precision_or_weight -
                         base_int_str_len] = '\0';
  }
}

void set_base_float_str_with_param(char *base_float_str_with_params,
                                   char *base_float_str, double number,
                                   struct S21_sprintf_param cure_param) {
  float_to_str(base_float_str, number, cure_param);
  if (s21_strlen(cure_param.flag) != 0) {  // проверяем флаги
    char sign = '0';
    set_sign(&sign, number, cure_param);
    if (s21_strchr(cure_param.flag, '-')) {  // минус
      if (sign != '0') {
        set_sign_base_int_str(sign, base_float_str);
      }
      s21_strcat(base_float_str_with_params, base_float_str);
      // соединяем base_str_with_params с base_float_str
      set_precision_or_width_to_int_str(cure_param.width, base_float_str,
                                        base_float_str_with_params, ' ');
      // ставим ширину в base_float_with_params
    } else {
      if (sign != '0') {
        set_sign_base_int_str(sign, base_float_str);
        // ставим минус в base_float_str
      }
      set_precision_or_width_to_int_str(cure_param.width, base_float_str,
                                        base_float_str_with_params, ' ');
      // ставим ширину в base_float_with_params
      s21_strcat(base_float_str_with_params, base_float_str);
      // соединяем base_str_with_params с base_float_str
    }

  } else {
    if (number < 0) {
      set_sign_base_int_str('-', base_float_str);
    }
    set_precision_or_width_to_int_str(cure_param.width, base_float_str,
                                      base_float_str_with_params, ' ');
    // ставим ширину в base_float_with_params
    s21_strcat(base_float_str_with_params, base_float_str);
  }
}

void float_to_str(char *base_float_str, double number,
                  struct S21_sprintf_param cure_param) {
  char buffer_before_point[120] = "\0";
  // получаем часть до точки в виде строки
  base_int_to_str(buffer_before_point, (long int)number, cure_param);
  s21_strcat(base_float_str, buffer_before_point);
  int input_str_len = s21_strlen(base_float_str);
  if (cure_param.precision != 0) {
    base_float_str[input_str_len] = '.';
    base_float_str[input_str_len + 1] = '\0';
  }
  char buffer_after_point[120] = "\0";
  long after_point =
      round((fabs(number - (int)number) + 1) *
            pow(10, cure_param.precision));  // округлённое число после точки
  base_int_to_str(buffer_after_point, after_point, cure_param);
  // получаем число после точки
  del_first_simb(buffer_after_point);
  s21_strcat(base_float_str, buffer_after_point);
}

void del_first_simb(char *buffer_after_point) {
  int i = 0;
  while (buffer_after_point[i] != '\0') {
    buffer_after_point[i] = buffer_after_point[i + 1];
    i++;
  }
}

void set_int_precision(int precision, char *base_int_str) {
  // добавляет точность в строку
  char buffer[1024] = "\0";
  int base_int_str_len = s21_strlen(base_int_str);
  for (int i = 0; i <= (precision - base_int_str_len); i++) {
    // забивает баффер нулями

    if (i == precision - base_int_str_len) {
      buffer[i] = '\0';
    } else {
      buffer[i] = '0';
    }
  }

  s21_strcat(buffer, base_int_str);
  // добавляет в баффер строку, в которой число
  s21_strcpy(base_int_str, buffer);  // копирует баффер в исходную строку
}
void set_sign_base_int_str(char sign, char *base_int_str) {
  // добавляет знак в строку
  char buffer[1024] = "\0";
  buffer[0] = sign;
  buffer[1] = '\0';
  s21_strcat(buffer, base_int_str);
  // добавляет в баффер строку, в которой число
  s21_strcpy(base_int_str, buffer);  // копирует баффер в исходную строку
}
void set_string_with_params_str(char *or_input_str,
                                char *base_string_str_with_params,
                                struct S21_sprintf_param cure_param) {
  char input_str[2048] = "\0";
  s21_strcpy(input_str, or_input_str);
  int input_len = s21_strlen(input_str);
  char buffer[1024] = "\0";
  if (input_len > cure_param.precision) {
    s21_strncpy(buffer, input_str, cure_param.precision);
    s21_strcpy(input_str, buffer);
  }
  if (s21_strchr(cure_param.flag, '-')) {
    s21_strcat(base_string_str_with_params, input_str);  // добавляем саму
                                                         // строку
    set_precision_or_width_to_int_str(cure_param.width, input_str,
                                      base_string_str_with_params, ' ');
    // добавляем ширину
  } else {
    set_precision_or_width_to_int_str(cure_param.width, input_str,
                                      base_string_str_with_params, ' ');
    // добавляем ширину
    s21_strcat(base_string_str_with_params, input_str);  // добавляем саму
                                                         // строку
  }
}
