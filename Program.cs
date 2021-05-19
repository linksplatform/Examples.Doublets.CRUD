using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.Memory.United.Generic;

// A doublet links store is mapped to "db.links" file:
using var links = new UnitedMemoryLinks<uint>("db.links");

// A creation of the doublet link: 
var link = links.Create();

// The link is updated to reference itself twice (as a source and a target):
link = links.Update(link, link, link); // Arguments are: address, source, target

// Read operations:
Console.WriteLine($"The number of links in the data store is {links.Count()}.");
Console.WriteLine("Data store contents:");
var any = links.Constants.Any; // Means any link address or no restriction on link address
var query = new Link<uint>(any, any, any); // Arguments are: address, source, target
links.Each((link) => {
    Console.WriteLine(links.Format(link));
    return links.Constants.Continue;
}, query);

// The link's content reset:
link = links.Update(link, default, default);

// The link deletion:
links.Delete(link);
