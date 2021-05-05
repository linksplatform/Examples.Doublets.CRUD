using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.Memory.United.Generic;

// A doublet links store is mapped to "db.links" file:
using var links = new UnitedMemoryLinks<uint>("db.links");

Console.WriteLine("Hello World!");

// A creation of the doublet link: 
var link = links.Create();

// The link is updated to reference itself twice (as a source and a target):
link = links.Update(link, link, link);

// Read operations:
Console.WriteLine($"The number of links in the the data store is {links.Count()}.");
Console.WriteLine("Data store contents:");
var query = new Link<uint>(links.Constants.Any, links.Constants.Any, links.Constants.Any);
links.Each((link) => {
    Console.WriteLine($"{links.Format(link)}");
    return links.Constants.Continue;
}, query);

// The link's content reset:
link = links.Update(link, default, default);

// The link deletion:
links.Delete(link);
