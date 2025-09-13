[![Состояние сборки](https://github.com/linksplatform/Examples.Doublets.CRUD/workflows/CI/badge.svg)](https://github.com/linksplatform/Examples.Doublets.CRUD/actions?workflow=CI)

# Examples.Doublets.CRUD.Rust ([english version](https://github.com/linksplatform/Examples.Doublets.CRUD/blob/main/rust/README.md))

Пример для быстрого старта, который показывает как создать, прочитать, обновить и удалить первую [связь](https://github.com/Konard/LinksPlatform/wiki/%D0%A7%D0%90%D0%92%D0%9E#%D0%A7%D1%82%D0%BE-%D1%82%D0%B0%D0%BA%D0%BE%D0%B5-%D1%81%D0%B2%D1%8F%D0%B7%D1%8C) используя [Дуплеты](https://github.com/linksplatform/Data.Doublets) на языке Rust.

## Для запуска требуется
* Linux, macOS или Windows
* [Rust](https://rustup.rs/)
* crate [doublets](https://crates.io/crates/doublets)

## [Код](https://github.com/linksplatform/Examples.Doublets.CRUD/blob/main/rust/src/main.rs)

```rust
use doublets::{data, mem, unit, Doublets, DoubletsExt, Links};

fn main() -> Result<(), doublets::Error<usize>> {
    // Хранилище дуплетов привязывается к файлу "db.links":
    let mem = mem::FileMapped::from_path("db.links")?;
    let mut store = unit::Store::<usize, _>::new(mem)?;

    // Создание связи-дуплета:
    let link = store.create_link(1, 1)?;

    // Операции чтения:
    println!("Количество связей в хранилище данных: {}.", store.count_links([store.constants().any, store.constants().any, store.constants().any]));
    println!("Содержимое хранилища данных:");
    
    // Означает любой адрес связи или отсутствие ограничения на адрес связи
    let any = store.constants().any;
    // Аргументы запроса интерпретируются как ограничения
    store.each_iter([any, any, any]).for_each(|link| {
        println!("{link:?}");
    });

    // Сброс содержимого связи:
    let updated_link = store.update_link(link, 0, 0)?;

    // Удаление связи:
    store
        .delete_with(updated_link, |before, after| {
            data::Flow::Continue
        })
        .map(|_| ())
}
```

Ожидаемый вывод:

```
Количество связей в хранилище данных: 1.
Содержимое хранилища данных:
[1, 1, 1]
```

Посмотрите [документацию по doublets](https://docs.rs/doublets) чтобы изучить подробности.

## Ищите что-то интереснее?
* [Сравнение между SQLite и Дуплетами](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Поисковый движок со встроенным поисковым роботом, который хранит веб-страницы в Дуплетах](https://github.com/linksplatform/Crawler)