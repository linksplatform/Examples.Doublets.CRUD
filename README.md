# HelloWorld.Doublets.DotNet
A quick start example that shows how to create a first link using Platform.Data.Doublets package:

```C#
using System;
using Platform.Data.Doublets;
using Platform.Data.Doublets.ResizableDirectMemory;

namespace HelloWorld.Doublets.DotNet
{
  class Program
  {
    static void Main()
    {
      using (var links = new ResizableDirectMemoryLinks<uint>("db.links"))
      {
          var link = links.Create();
          link = links.Update(link, link, link);
          Console.WriteLine("Hello World!");
          Console.WriteLine($"This is my first link: ({link}:{links.GetSource(link)}->{links.GetTarget(link)}).");
      }
    }
  }
}
```
