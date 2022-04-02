using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.Memory.United.Generic;

// A doublet links store is mapped to the "db.links" file:
using var links = new UnitedMemoryLinks<uint>("db.links");

// Creating a doublet link: 
var link = links.Create();

// The link is updated to reference itself twice (as a source and as a target):
// The passed arguments are: an updated address, a new source, and a new target
link = links.Update(link, newSource: link, newTarget: link);

// Read operations:
Console.WriteLine($"The number of links in the data store is {links.Count()}.");
Console.WriteLine("Data store contents:");
// Means any link address or that there is no restriction on link address
var any = links.Constants.Any; 
// The arguments of a query are restrictions: on address, on source, on target
var query = new Link<uint>(index: any, source: any, target: any);
links.Each((link) => {
    Console.WriteLine(links.Format(link));
    return links.Constants.Continue;
}, query);

// Cleaning (resetting) the contents of the link:
link = links.Update(link, newSource: default, newTarget: default);

// Removing the link
links.Delete(link);
