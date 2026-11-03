#pragma once

namespace miit::algebra {

    /**
     * @brief Абстрактный базовый класс для всех генераторов чисел.
     */
    class Generator {
    public:
        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Generator() = default;

        /**
         * @brief Генерирует следующее целое число.
         * @return Сгенерированное число.
         */
        virtual int generate() = 0;
    };

}
