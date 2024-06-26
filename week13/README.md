# Задачи - ООП, Седмица 13, 16.05.2024

*Този файл е копие на задачите от: [syndamia.com/teaching/oop-2023/week13](https://syndamia.com/teaching/oop-2023/week13)*

&:warn Навсякъде, където е нужно, реализирайте голяма петица.

## Преговорни

### Задача 1 - Множествено наследяване

Реализирайте клас `String`, който запазва динамичен низ с фиксиран размер.

Реализирайте клас `IndexArray`, който запазва динамичен масив с фиксиран размер от цели числа - индекси.

&:warn **Не** правете общ родител, който имплементира динамичен масив!

Реализирайте наследник на двата класа, `WordsString`, при който индексите определят началото на всяка дума от запазения низ.
Индексите се дефинират при конструктора.

## Лесни

### Задача 2

<!-- Диамант -->

Реализирайте шаблонен клас `Container`, който съхранява масив с фиксиран размер от елементи с подаден тип.
**Не** трябва да реализирате нищо повече от задължителните компоненти (голяма петица).

Реализирайте негов наследник `Indexable`, който реализира оператор[].

Реализирайте втори негов наследник `Resizeable`, който реализира член-функция `InsertAt`, приемаща елемент и индекс, и която вмъква елемента на даден индекс.
Разбира се, може да се наложи оразмеряване на масива.

Реализирайте наследник `Vector` на `Indexable` и `Resizeable`, който реализира оператор[] и член-функции:

- `pop_back`, премахваща последния елемент
- `pop_front`, премахваща първия елемент
- `push_back`, приемаща елемент който се вкарва в края на масив
- `push_front`, приемаща елемент който се вкарва в началото на масив

&:important Не забравяйте за диамантния проблем!

### Задача 3

<!-- Диамант -->

Реализирайте клас `User`, който запазва потребителско име и парола като низове с произволна дължина, заедно с булев флаг `banned`, определящ дали акаунтът може да прави действия.
Потребителско име не може да съдържа шпации.

Реализирайте клас `Thread`, който запазва масив с произволна дължина, от низове с произволна дължина.
Имплементирайте член-функция:

- `PostMessage`, която приема потребител и негово съобщение и добавя съобщението с потребителското име като един низ.
  Ако потребителя е `banned`, тогава хвърлете грешка.

Реализирайте наследник `ThreadModerator` на `User`, който може да променя `Thread` обекти, без да се нуждае от публични член-функции в `Thread`.
Имплементирайте методи:

- `RemoveMessage`, който приема `Thread` и индекс на съобщение и премахва съответното съобщение
- `RemoveByUser`, който приема `Thread` и потребител, и премахва всички съобщения, направени от дадения потребител

Реализирайте наследник `UserModerator` на `User`, който може да променя `User` обекти, без да се нуждае от публични член-функции в `User`.
Имплементирайте методите:

- `BanUser`, който приема потребител и вдига `banned` флага
- `UnbanUser`, който приема потребител и сваля `banned` флага

Реализирайте наследник `Administrator` на `ThreadModerator` и `UserModerator`, който може да прави всичко, което и родителите могат.

&:important Не забравяйте за диамантния проблем!

## Трудни

### Задача 4

Реализирайте абстрактен клас `ShopLocation`, който съхранява член-данни:

- адрес като низ с максимална дължина от 511 знака.
  Всеки адрес съдържа произволни символи и задължително завършва на число, определящо неговия район.
- време на отваряне и време на затваряне

Имплементирате методи:

- `IsOpen`, който връща по подаден час дали локацията е отворена
- `InCenter`, който връща дали локацията се намира в центъра на града.
  Всички адреси с регион, по-малък от 11, се намират в центъра.

Реализирайте шаблонен клас `Inventory`, който съхранява **фиксиран** брой елементи и техните неотрицателни бройки (количества).
Имплементирайте член-функции:

- оператор[], който връща елемент на дадения индекс
- оператор(), който връща бройка на елемент на дадения индекс
- `Stock`, приемащ индекс на елемент и бройка (положителна/отрицателна) с която бройката на дадения елемент се променя.
  Бройката може да бъде най-малко 0.
- `List`, който връща всички елементи и техните индекси

Реализирайте абстрактен шаблонен наследник `DeliverableInventory` на `Inventory`, който е инвентар с максимум 2048 елемента и допълнително задължава имплементацията на:

- `ShippingDelay`, който приема адрес и връща времето в което ще може да се достави обекта

Реализирайте наследник на `DeliverableInventory`, склад `Warehouse`, който допълнително запазва разстояние от града в километри и имплементира `ShippingDelay` по следната логика:

- доставки в центъра отнемат един ден + регионът в който се доставя
- доставки извън центъра отнемат толкова време, колкото е нужно да се стигне до града ако пътува с 80 километра в час + времето което ще отнеме да се измине номер на региона на брой километри при скорост от 20 километра в час

Доставка не може да се случи преди 9 сутринта и след 18 вечерта.
Ако попадне в този диапазон, тогава се отлага за най-скорошния следващ възможен час.

Реализирайте шаблонен наследник магазин `Shop` на `ShopLocation` и `Inventory`, който е инвентар с максимум 256 елемента, запазващ:

- **оразмеряем** масив от низове с произволен размер, всеки низ който е "отчет на продажба"
- общо бройка продажби

и който имплементира методи:

- `SellItems`, който приема масив от идентификатори на обекти, намалява бройката на всеки от тях и създава нов отчет.
  Отчета е в произволен формат, но трябва да съдържа идентификаторите и бройките на всеки обект.
  Ако за някой обект няма достатъчно бройки или изобщо не се пази, хвърлете грешка.

Реализирайте шаблонен клас `WebStore`, който запазва оразмеряеми масиви от `Shop` и `Warehouse`.
Имплементирайте:

- оператор<<, който изкарва всички уникални (unique) обекти от всички магазини и складове, с индекс до тях
- `GetEstimate`, който приема индекс на уникален обект от всички магазини и складове, сегашно време и адрес, и изкарва на екрана всички магазини които са отворени в дадения час и кое е най-скорошното време в което може обектът да се достави от склад.
  Ако няма отворени магазини, ако няма магазин с наличност и так. нат. изкарайте съответно съобщение.

Последно реализирайте клас `Book`, който запазва заглавие на книга и име на автор като низове с максимална дължина от 127 знака.
Имплементирайте оператор<<, който изкарва съответната книга в произволен формат.

В главната функция реализирайте `WebStore` от книги, заедно с набор от книги, магазини и складове по ваш избор.
Нека в началото на програмата да приемате от потребителя сегашното време и адрес, след това изкарайте на екрана всички ункални книги с индекси.
Накрая потребителя може да въведе индекс на книга и да получи информация кои отворени сега магазини имат съответната книга и кога най-скоро може да бъде доставена от склад.
