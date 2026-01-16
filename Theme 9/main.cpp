#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class ApplicationSettings {
private:
    std::string logFileName;
    int windowWidth;
    int windowHeight;
    std::string language;

    // Приватный конструктор Singleton
    ApplicationSettings() : logFileName("app.log"), windowWidth(800), windowHeight(600), language("EN") {}

    // Запрет копирования
    ApplicationSettings(const ApplicationSettings&) = delete;
    ApplicationSettings& operator=(const ApplicationSettings&) = delete;

public:
    // Получение единственного экземпляра, возвращает статический бъект класса,
    // гарантирует что существует только 1 экземпляр
    static ApplicationSettings& getInstance() {
        static ApplicationSettings instance;
        return instance;
    }

    // Геттеры
    std::string getLogFileName() const { return logFileName; }
    int getWindowWidth() const { return windowWidth; }
    int getWindowHeight() const { return windowHeight; }
    std::string getLanguage() const { return language; }

    // Сеттеры
    void setLogFileName(const std::string& name) { logFileName = name; }
    void setWindowWidth(int width) { windowWidth = width; }
    void setWindowHeight(int height) { windowHeight = height; }
    void setLanguage(const std::string& lang) { language = lang; }

    // Загрузка настроек из файла
    void loadFromFile(const std::string& fileName) {
        std::ifstream file(fileName);
        if (!file) {
            std::cout << "Файл настроек '" << fileName << "' не найден. Используются значения по умолчанию.\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string key, value;
            if (std::getline(iss, key, '=') && std::getline(iss, value)) {
                if (key == "logFileName") logFileName = value;
                else if (key == "windowWidth") windowWidth = std::stoi(value);
                else if (key == "windowHeight") windowHeight = std::stoi(value);
                else if (key == "language") language = value;
            }
        }

        std::cout << "Настройки успешно загружены из файла '" << fileName << "'.\n";
    }

    // Сохранение настроек в файл
    void saveToFile(const std::string& fileName) const {
        std::ofstream file(fileName);
        if (!file) {
            std::cout << "Ошибка: не удалось сохранить файл настроек '" << fileName << "'.\n";
            return;
        }

        file << "logFileName=" << logFileName << "\n";
        file << "windowWidth=" << windowWidth << "\n";
        file << "windowHeight=" << windowHeight << "\n";
        file << "language=" << language << "\n";

        std::cout << "Настройки успешно сохранены в файл '" << fileName << "'.\n";
    }
};

int main() {
    // Получаем единственный экземпляр
    ApplicationSettings& settings = ApplicationSettings::getInstance();

    // Загружаем настройки из файла
    settings.loadFromFile("settings.txt");

    // Вывод текущих настроек
    std::cout << "\nТекущие настройки приложения:\n";
    std::cout << "Файл для логирования: " << settings.getLogFileName() << "\n";
    std::cout << "Размер окна: " << settings.getWindowWidth() << " x " << settings.getWindowHeight() << " пикселей\n";
    std::cout << "Язык приложения: " << settings.getLanguage() << "\n";

    // Изменяем настройки
    settings.setLogFileName("новый_лог.log");
    settings.setWindowWidth(1024);
    settings.setWindowHeight(768);
    settings.setLanguage("RU");

    // Сохраняем изменения
    settings.saveToFile("settings.txt");

    return 0;
}