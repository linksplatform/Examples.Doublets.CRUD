using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.Memory.United.Generic;

// A doublet links store is mapped to the "db.links" file:
using var links = new UnitedMemoryLinks<uint>("db.links");

// Creating a doublet link using new write handlers style:
// CreatePoint() extension method is equivalent to: links.Create(substitution: null, handler: null)
// It creates a point (link that references itself as source and target)
var link = links.CreatePoint();

// Alternative way to create using the new API directly:
// var link = links.Create(substitution: null, handler: null);
// Then update it to be self-referencing:
// var any = links.Constants.Any;
// var restriction = new Link<uint>(index: link, source: any, target: any);
// var substitution = new Link<uint>(index: link, source: link, target: link);
// link = links.Update(restriction: restriction, substitution: substitution, handler: null);

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

// Cleaning (resetting) the contents of the link using new write handlers style:
// Update operation with restriction (which link to update) and substitution (new values)
var resetRestriction = new Link<uint>(index: link, source: any, target: any);
var resetSubstitution = new Link<uint>(index: link, source: default, target: default);
link = links.Update(restriction: resetRestriction, substitution: resetSubstitution, handler: null);

// Removing the link using new write handlers style:
// Note: Delete operation also uses the new handlers style with restriction parameter
// links.Delete(restriction: new Link<uint>(index: link, source: any, target: any), handler: null);
