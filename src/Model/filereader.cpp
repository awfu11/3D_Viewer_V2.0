#include "filereader.h"

namespace awfl {
void FileReader::GetDataFromFile(Figure& figure, const std::string& path) {
  filePath_ = path;
  figure.ClearData();
  ReadData_(figure);
}

void FileReader::SetFileName(const std::string& path) { filePath_ = path; }

std::pair<std::size_t, std::size_t> FileReader::GetNumbers_() {
  std::size_t v = 0, e = 0;
  std::ifstream file(filePath_);
  if (!file.is_open()) {
    return {0, 0};
  }
  std::string buf;
  while (std::getline(file, buf)) {
    if (buf.compare(0, 2, "v ") == 0) {
      ++v;
    } else if (buf.compare(0, 2, "f ") == 0) {
      e += 4;
    }
  }
  file.close();
  return {v, e};
}

void FileReader::SplitInputString_(std::vector<std::string>& arr,
                                   std::string& buf) {
  std::size_t pos = 0;
  for (std::size_t i = 1; i < buf.length(); ++i) {
    if (buf[i - 1] == ' ' && buf[i] != ' ') {
      pos = i;
    } else if (buf[i - 1] != ' ' && buf[i] == ' ') {
      arr.push_back(buf.substr(pos, i - pos));
      pos = i;
    }
  }
  if (buf.back() != ' ') {
    arr.push_back(buf.substr(pos));
  }
}

void FileReader::ReadData_(Figure& figure) {
  std::pair<std::size_t, std::size_t> num = GetNumbers_();
  figure.initial_.reserve(3 * num.first);
  figure.edges_.reserve(2 * num.second);

  std::ifstream file(filePath_);
  if (!file.is_open()) {
    return;
  }

  std::string buf;
  while (std::getline(file, buf)) {
    if (buf.compare(0, 2, "v ") == 0) {
      double x = 0.0, y = 0.0, z = 0.0;
      if (sscanf(buf.c_str(), "v %lf %lf %lf", &x, &y, &z) == 3) {
        figure.initial_.insert(figure.initial_.end(), {x, y, z});
      }
    } else if (buf.compare(0, 2, "f ") == 0) {
      buf = buf.substr(2);

      std::vector<std::string> arr;
      SplitInputString_(arr, buf);

      int first = std::atoi(arr[0].c_str()) - 1, num = 0;
      if (first >= 0) {
        figure.edges_.insert(figure.edges_.end(), {first, first});
      }
      for (std::size_t i = 1; i < arr.size(); ++i) {
        if ((num = std::atoi(arr[i].c_str()) - 1) >= 0) {
          figure.edges_.insert(--figure.edges_.end(), {num, num});
        }
      }
    }
  }
  file.close();
}
}  // namespace awfl
