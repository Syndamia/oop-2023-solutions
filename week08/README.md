# Задачи - ООП, Седмица 8, 11.04.2024

*Този файл е копие на задачите от: [syndamia.com/teaching/oop-2023/week8](https://syndamia.com/teaching/oop-2023/week8)*

## Преговорни

### Задача 1 - Голяма петица

Имплементирайте клас `StreetList`, който запазва имената на улици (низове с произволна дължина) в динамичен масив.
Може да се добавят нови имена в края на списъка, като съответния (вътрешен) масив трябва да се уголеми.

Имплементирайте голяма петица за класа.

### Задача 2 - Файлове и класове

Имплементирайте клас `Person`, който запазва трите имена (низове с произволна дължина) и идентификационния номер (цяло неотрицателно число) на човек.
Имплементирайте голяма петица.

Имплементирайте методи `SaveText` и `LoadText`, които съответно записват и четат (тоест член-данните стават равни на тези от файла) данните си в/от **текстови** файл с подадено име.
Аналогично имплементирайте `SaveBinary` и `LoadBinary`, които работят с **двоични** файлове.

## Лесни

### Задача 3

Имплементирайте шаблонната структура `Pair`, която приема два типа и запазва по една стойност от всеки тип.

### Задача 4

Имплементирайте клас `FloatArray`, който съдържа списък с числа с плаваща запетая.
Може да добавяте нови числа в края на този списък.
Имплементирйате голяма петица.

Имплементирайте оператори:

- += и +, които конкатенират два FloatArray-я. += вмъква елементите от десния масив в края на левия, + връща нов масив в който първо са елементите от левия масив и след тях са тези от десния.
- += и +, които приемат FloatArray и число (с плаваща запетая) и го прибавят към всеки елемент на FloatArray-я
- [], които връщат референция към елементът на подадения индекс. При невалиден хвърлят грешка.
- == и !=, които сравняват два FloatArray-я покомпонентно.
  Ако се различават по брой елементи или ако имат две различни стойности на еднакъв индекс, тогава не са равни.
- <<, който вмъква всички стойности в подадения поток, разделени с шпация
- >>, който презаписва всички стойности, разделени с шпация, четейки от подадени поток

### Задача 5

Имплементирайте класът и неговите оператори от предходната задача като темплейтен (шаблонен) клас с име `DynamicArray`.
Очевидно шаблонния тип определя типа на списъка с елементи.

### Задача 6

Имплементирайте клас `NumberInput`, който запазва целочислена стойност.
В конструктора се подава минимална и максимална възможна стойност, след това (все още в конструктора) се изкарва на екрана съответно съобщение и се приема потребителски вход.
Ако той не е валиден или е извън подадения обхват, трябва да хвърлите грешка.

В main създайте обект от този клас.
Ако се хвърли грешка, прихванете я, изкарайте на екрана съответното съобщение и пробвайте пак.
Това се повтаря докато обекта не е успешно създаден, след което изкарвате въведената стойност по две.

### Задача 7

Имплементирайте клас `UserError`, чиято употреба е да се хвърля като грешка.
За тази цел нека да запазва два низа, които се приемат в конструктора: името на клас и името на член-данната.

Имплементирайте голяма петица и оператор<<, който изкарва съобщение с информация за класа и член-данната в подадения поток.
Следете бройката на създадени `UserError` инстанции в самия клас (статична променлива) и имплементирате нужната (статична) член-функция, която връща този брой.

Преобразувайте последната задача, така че да хвърля грешка от този клас.
В края на програмата изкарайте колко грешки са се хвърлили **използвайки статичните членове на UserError**.

## Трудни задачи

### Задача 8

Имплементирайте шаблонен клас `UserInput`, който запазва стойност от подадения тип.
Ако типа е указател, тогава заделяте динамична памет за един такъв елемент.
За проверка на типа използвайте [partial template specialization](https://en.cppreference.com/w/cpp/language/partial_specialization).

В шаблона (`template <...>`) се приема указател към валидираща функция, която приема стойността от съответния тип и връща булева стойност.
В конструктора се приема от входа нужната стойност и ако стойността е неуспешно приета или валидиращата функция върне false, тогава хвърляте грешка.
Ако типа е указател, не забравяйте да освободите паметта.

В класа следете статично за броя пъти когато е хвърлена грешка.

### Задача 9

&:important В тази задача се изикват помощни класове, прочетете цялото условие преди имплементиране!

Имплементирайте шаблонен клас `Dictionary`, който запазва два динамично-заделени масива: първия е със стойност от подадения тип, втория е с низове.
Низовете ще се използват за индексиране, вместо числа.
Разбира се, очаквайте да може да се уразмерява.
Имплементирайте голяма петица.

Имплементирайте оператор:

- <<=, който вмъква всички стойности от десния `Dictionary` в левия
- [], който приема низ и връща референция "към" стойността.
  Ако няма записана стойност на съответния индекс, тогава връщате референция в която може да се запише стойност.
- [], който приема число, което се конвертира до низ и работи както предходния оператор
- [], който приема низове (или числа), разделени със запетая и връща "масив" само с тези стойности
- delete, който приема стойност, върната от оператор[] и "премахва" съответната стойност от `Dictionary`
- префиксен++, префиксен+ и префиксен-, които ще се използват за итериране.
  - ++ връща инкрементира индекса на сегашната стойност.
    Ако индекса е равен на броя запазени стойности, тогава става нула.
    По подразбиране индекса е броя.
    Връща true ако след инкрементиране индекса не е броя.
  - + връща референция към стойността на сегашния индекс
  - - връща сегашния (низов) индекс
- ->, такъв че можем да правим `a->(&func1)->(&func2)` и `a->[&func3]->[&func4]`.  
  Върху всяка двойка индекс-стойност се прилагат &func1 и &func2 (приемат индекс и стойност като параметри), които връщат нова стойност, заместваща сегашната.  
  &func3, &func4 аналогично приемат индекс и стойност, но връщат нов индекс.

В края на задачата трябва да можете да правите:

```cpp
int doubleUp(const char* index, int value) {
    return value * 2;
}
int sumIndexValue(const char* index, int value) {
    return atoi(index) + value;
}
const char* indToName(const char* index, int value) {
    if (strcmp(index, "2")) {
        return "two";
    }
    return index;
}

int main() {
    Dictionary<int> a;
    a["first"] = 8;
    a[2] = 13;
    a[89] = -68;

    Dictionary<int> b;
    b["wow"] = 99;
    b["nth"] = 773;

    a <<= b;

    /* някакъв тип */ two = a["first", 2];

    delete a["wow"];

    a->(&doubleUp)->(&sumIndexValue)->[&indToName];

    while (++a) {
        std::cout << +a << " at " << -a << ",";
        /* Ще изкара на конзолата:
         * 16 at first,52 at two,-12104 at 89,1546 at nth,
         */
    }
}
```
