int
main (int argc, char* argv[])
{
  using namespace hello;

  if (argc < 2)
  {
    println ("error: missing name");
    return 1;
  }

  println ("Hello, {}!", argv[1]);
}
