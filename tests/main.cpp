#include <iostream>
#include <string>

#include "../csql/src/csql.h"

int main() {
  csql::Database db;

  db.execute(
      "create table users ({key, autoincrement} id :int32, {unique} login: string[32] = "
      "\"hello\", password_hash: bytes[8] = 0x0011223344556677, is_admin: bool = false)");

  db.execute(
      "insert (id=1, login=\"admin\", password_hash=0x0011223344556677, is_admin=true) to "
      "users");
  db.execute(
      "insert (id=2, login=\"user1\", password_hash=0x0011223344556677) to "
      "users");
  db.execute(
      "insert (id=3, login=\"user2\", password_hash=0x2233445566778899) to "
      "users");

  db.exportTableToCSV("users", "users.csv");

  return 0;
}