use doublets::mem::united::Store;
use doublets::Doublets;
use platform_data::Flow::Continue;
use platform_mem::FileMappedMem;
use std::error::Error;
use std::fs::File;

fn main() -> Result<(), Box<dyn Error>> {
    let mem = FileMappedMem::new(
        File::options()
            .create(true)
            .read(true)
            .write(true)
            .open("db.links")?,
    )?;
    let mut links = Store::<u64, _>::new(mem)?;

    let link = links.create()?;
    let link = links.update(link, link, link)?;

    let any = links.constants().any;
    links.try_each_by([any, any, any], |link| {
        println!("{}", link);
        Continue
    });

    links.delete(link)?;
    Ok(())
}
