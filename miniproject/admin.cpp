#include "admin.h"
#include "file.h"

Admin :: Admin(string id, string username, string password)
    : User(id, username, password, "Admin") {
}


void Admin::deleteUser(string userId) {
  
        vector<User*> users = loadUsersFromFile(); // بارگذاری کاربران

        auto it = find_if(users.begin(), users.end(), [&userId](User* user) {
            return user->getId() == userId;
            });

        if (it != users.end()) {
            delete* it;  // حذف کاربر از حافظه
            users.erase(it);  // حذف از وکتور
            cout << "User deleted.\n";
        }

        // ذخیره مجدد کاربران به فایل
        saveUsersToFile(users);
    }



void Admin::restoreUser(string userId) {
    // بارگذاری کاربران از فایل
    vector<User*> users = loadUsersFromFile();

    // جستجو و بازیابی کاربر حذف شده
    for (auto& user : users) {
        if (user->getId() == userId) {
            // اگر کاربر پیدا شد، بازیابی کنیم (مثلاً تغییر وضعیت به فعال)
            user->setRole("Active");  // فرض کن که نقش رو به Active تغییر می‌ده
            break;
        }
    }

    // ذخیره‌سازی تغییرات به فایل
    saveUsersToFile(users);

    cout << "User with ID " << userId << " restored." << endl;
}

void Admin::viewCourseList() {
    for (auto course : courses) {
        cout << "Course ID: " << course->getCourseId() << ", Name: " << course->getCourseName() << endl;
    }
}

void Admin::viewStatistics() {
    // نمایش آمار کلی از دروس
    for (auto course : courses) {
        cout << "Course: " << course->getCourseName() << ", Avg Grade: " << course->getAverageGrade() << endl;
    }
}

void Admin::createUser(vector<User*>& users, User* newUser) {
    users.push_back(newUser);  // مستقیم به وکتور اصلی اضافه کن
    saveUsersToFile(users);    // بعد ذخیره کن
    cout << "User " << newUser->getRole() << " created successfully." << endl;
}
