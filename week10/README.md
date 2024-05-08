# Задачи - ООП, Седмица 10, 25.04.2024

*Този файл е копие на задачите от: [syndamia.com/teaching/oop-2023/week10](https://syndamia.com/teaching/oop-2023/week10)*

## Преговорни

&:warn Моля, не отделяйте на преговорните задачи повече от 30мин

### Задача 1 - Шаблони

Реализирайте шаблонен клас `Array`, който запазва динамично-заделен и оразмеряем масив от елементи с подаден тип.
Имплементирайте голяма четворка.

### Задача 2 - Оператори

За предходния шаблонен клас имплементирайте оператори:

- [], който връща рефернция към елемента на подадения индекс
- == и !=, които сравняват поелементно
- +, += които конкатенират (слепват) два масива

### Задача 3 - Грешки

Имплементирайте функция, която приема име на текстов файл и изкарва на екрана първия ред от него.
Ако файлът не може да бъде отворен, хвърлете грешка - низ.
Ако във файлът няма други редове (няма знакът `'\n'`), тогава върнете число - размерът на файла.

В главната функция, приемете името на файла от потребителския вход и извикайте функцията.
Ако файлът не може да бъде отворен, тогава изкарайте хвърлената грешка на терминала и приключете програмата (успешно).
Ако няма други редове в него, тогава изкарайте съобщението "In X characters, there is no newline!", където X е хвърленото число, и приемете пак име на файла от потребителския вход.

## Лесни

### Задача 4

Реализирайте клас `Time24`, който запазва час и минути (в 24-часов формат) в две отделни целичислени член-данни.
Имплементирайте член-функция `Print24`, която изкарва часа на екрана в 24-часов формат.
Нека конструкторът му приема две целочислени променливи, една за часа и втора за минутите.

Реализирайте негов наследник `Time12`, който имплементира метод `Print12`, принтиращ часа в 12-часов формат.
Имплементирайте и негов конструктор, който приема две целочислени променливи (една за часа и една за минутите), заедно с булева променлива описваща дали часа е следобеден или не.

### Задача 5

Реализирайте клас `FN`, който запазва факултетен номер като неотрицателно цяло число от 5 цифри.
Реализирайте негов наследник `ModernFN`, който запазва и начален низ, състоящ се от цифра, две букви и още две цифри.

Имплементирайте конструктори, като този на `FN` приема число, докато този на `ModernFN` приема низ, състоящ се от целия факултетен номер (и трябва да конвертирате последните 5 цифри).
Имплементирайте метод `PrintOldFN` на класа `FN` и метод `PrintNewFN` на класа `ModernFN`, които изкарват целия факултетен номер на съответния клас.

### Задача 6

Реализирайте клас `Grade`, който запазва оценка (от 2 до 6) като неотрицателна целочислена член-данна.
Реализирайте и негов наследник `GradeWithName`, който запазва и името на оценката като низ с произволна дължина.

Конструктора на `Grade` приема само числовата стойност, докато този на наследника приема и името на оценката.
Имплементирайте голяма петица на `GradeWithName`.

### Задача 7

Реализирайте клас `String`, който запазва низ с произволна дължина.
Имплементирайте голяма петица и член-функция `At`, която приема индекс и връща референция към буквата на този индекс (при невалиден индекс хвърляте грешка).

Реализирайте негов наследник `FileString`, който запазва и името на текстов файл като низ с произволна дължина.
Ако е нужно, имплементирайте голяма петица.

Самия низ в `FileString` е първия низ (начало първата буква и край `'\n'`) от файла с подадено име.

Имплементирайте метод `ChangeAt`, който приема индекс и нова буква, променя буквата на дадения индекс с подадената и обновява файла със запазеното име.

### Задача 8

Реализирайте клас `User`, който запава име и парола като два низа с произволна дължина.
Реализирайте негов наследник `Moderator`, който запазва и подпис, който също е низ с произволна дължина.
Реализирайте наследник `Administrator` на `Moderator`, който запазва и оразмеряващ се масив от цели числа.

Идеята е, че всяко действие от модератор или администратор се "подписва" публично (за да се знае, че той го е направил, дори да си смени името), а за администратор допълнително пазим масив от идентификатори на форуми, които администрира.

За всеки клас имплементирайте голяма петица и гетъри и сетъри за името и паролата, когато е нужно.
За `Moderator` имплементирайте гетър за подписа, но без сетър.
За `Administrator` имплементирайте методи за добавяне и премахване на идентификатор на форум.

### Задача 9

Реализирайте клас `CommunicationPacket`, който запазва начален и краен адрес като две неотрицателни цели числа, заедно с трето число за размера на данните.
В този клас никога няма данни, затова размера винаги е нула.

Реализирайте негови наследници `StringPacket` и `IntPacket`, където първия запазва и низ с произволна дължина (и дължината му е размера на данните) докато втория запазва и едно цяло число (и размера на `int` е размера на данните).

Размерът не се подава на конструктори, а се изчислява в конструктори.
Имплементирайте голяма петица и конструктори с нужните параметри.

### Задача 10

Реализирайте клас `String`, който запазва низ с произволна дължина, и имплементира оператори ==, !=, + (който връща нов низ с конкатенацията на двата низа).

Реализирайте негов наследник `ModifiableString`, който имплементира оператор[]  (връщащ референция към буквата на дадения индекс) и оператор+=.

Реализирайте наследник на `ModifiableString`, `ShowableString`, който имплементира оператори << и >>.
Реализирайте наследник на `ModifiableString`, `SaveableString`, който имплементира методи write и read, приемащи име на двоичен файл и записващи или четещи низа от този файл.

За всички класове имплементирайте голяма петица, когато е нужно.

## Трудни

### Задача 11

Реализирайте шаблонен клас `Array`, който запазва оразмеряем масив с елементи от подаден тип.
Имплементирайте оператор== и оператор!=, заедно с метод `isEmpty`.
Концептуално идеята е, че този масив не може да се променя след като му се въведат стойностите от конструктора.

Реализирайте негов наследник `PrintableArray`, който имплементира оператори << и >>.
Реализирайте наследник `SaveableArray` на `Array`, който имплементира методи write и read, приемащи име на файл и булева стойност дали е двоичен или не, и съответно прочитат или запазват елементите от този масив във файла.

Реализирайте трети наследник, `ModifiableArray`, на `Array`, в който са имплементирани член-функции:

- `push`, която приема елемент и го вмъква в (десния) края на масива
- `pop`, който премахва елемент от (десния) края на масива
- `last`, който връща последния елемент от масива

Може да се налага масива да се оразмерява.
Като подсказка, имплементирайте си метод, наличен за класа и наследници, който вмъква елемент на произволен индекс.

Реализирайте наследник `IndexableArray` на `ModifiableArray`, който имплементира оператор[].
Ако индекса е след края, тогава "вмъквате" елементи по подразбиране между края и подадения индекс, и връщате елемента от сега новия край.
Реализирайте наследник `FrontableArray` на `ModifiableArray`, който имплементира методи `pushf` и `popf`, който работят като `push` и `pop`, но с елемента в началото на масива (първия елемент).