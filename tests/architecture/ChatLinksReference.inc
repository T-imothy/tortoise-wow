std::set<uint32> ChatHelper::ExtractAllItemIds(const std::string& text)
{
    std::set<uint32> ids;

    std::regex rgx("Hitem:[0-9]+");
    auto begin = std::sregex_iterator(text.begin(), text.end(), rgx);
    auto end = std::sregex_iterator();
    for (std::sregex_iterator i = begin; i != end; ++i)
    {
        std::smatch match = *i;
        ids.insert(std::stoi(match.str().erase(0, 6)));
    }

    return ids;
}

std::set<uint32> ChatHelper::ExtractAllQuestIds(const std::string& text)
{
    std::set<uint32> ids;

    std::regex rgx("Hquest:[0-9]+");
    auto begin = std::sregex_iterator(text.begin(), text.end(), rgx);
    auto end = std::sregex_iterator();
    for (std::sregex_iterator i = begin; i != end; ++i)
    {
        std::smatch match = *i;
        ids.insert(std::stoi(match.str().erase(0, 7)));
    }

    return ids;
}
