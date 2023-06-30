# Title: Rising Temperature
# Source: https://leetcode.com/problems/rising-temperature
# Difficulty: Easy
# Tags: Database
# Author: nxphuc
# Time Complexity: 
# Space Complexity: 
# Note: 

# Table: Weather
# +---------------+---------+
# | Column Name   | Type    |
# +---------------+---------+
# | id            | int     |
# | recordDate    | date    |
# | temperature   | int     |
# +---------------+---------+
# id is the primary key for this table.
# This table contains information about the temperature on a certain day.
#  
# Write an SQL query to find all dates' Id with higher temperatures compared to its previous dates (yesterday).
# Return the result table in any order.
# The query result format is in the following example.
#  
# Example 1:
# Input: 
# Weather table:
# +----+------------+-------------+
# | id | recordDate | temperature |
# +----+------------+-------------+
# | 1  | 2015-01-01 | 10          |
# | 2  | 2015-01-02 | 25          |
# | 3  | 2015-01-03 | 20          |
# | 4  | 2015-01-04 | 30          |
# +----+------------+-------------+
# Output: 
# +----+
# | id |
# +----+
# | 2  |
# | 4  |
# +----+
# Explanation: 
# In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
# In 2015-01-04, the temperature was higher than the previous day (20 -> 30).

# Write your MySQL query statement below
SELECT p1.id
FROM Weather p1, Weather p2
WHERE p1.temperature > p2.temperature and p1.recordDate = p2.recordDate + INTERVAL 1 DAY;
