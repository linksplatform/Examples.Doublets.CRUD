use doublets::{data, mem, unit, Doublets, DoubletsExt, Links};

fn main() -> Result<(), doublets::Error<usize>> {
    // A doublet links store is mapped to the "db.links" file:
    let mem = mem::FileMapped::from_path("db.links")?;
    let mut store = unit::Store::<usize, _>::new(mem)?;

    // Creating a doublet link:
    let link = store.create_link(1, 1)?;

    // Read operations:
    println!("The number of links in the data store is {}.", store.count_links([store.constants().any, store.constants().any, store.constants().any]));
    println!("Data store contents:");
    
    // Means any link address or that there is no restriction on link address
    let any = store.constants().any;
    // The arguments of a query are restrictions: on address, on source, on target
    store.each_iter([any, any, any]).for_each(|link| {
        println!("{link:?}");
    });

    // Cleaning (resetting) the contents of the link:
    let updated_link = store.update_link(link, 0, 0)?;

    // Removing the link
    store
        .delete_with(updated_link, |before, after| {
            data::Flow::Continue
        })
        .map(|_| ())
}