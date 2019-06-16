package src;

public class PrintBanner extends PrintClass
{
    private Banner banner;
    public PrintBanner(String string)
    {
        this.banner = new Banner(string);
    }
    public void printWeak()
    {
        banner.showWithParen();
    }
    public void printStrong()
    {
        banner.showWithAster();
    }
}
