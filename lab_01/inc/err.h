#ifndef __ERR_H__
#define __ERR_H__

/// @brief  Коды ошибок
enum err_t
{
    OK,             /// Ошибок нет
    ERR_IO,         /// Ошибка ввода-вывода
    ERR_RANGE,      /// Ошибка значений
    ERR_FILE_OPEN,  /// Ошибка при открытии файла
    ERR_FILE_NAME,  /// Ошибка в имени файла
    ERR_MEM,        /// Ошибка памяти
    ERR_UI,         /// Ошибка интерфейса
    ERR_TASK,       /// Ошибка в запросе
    ERR_PARAM,      /// Ошибка в параметрах функции
    ERR_EDGE        /// Ошибка в формате объекта
};

/**
 * @brief Выводит сообщение для кода ошибки
 *
 * @param err [in] - код ошибки
 */
void print_err_msg(const err_t err);

#endif
