pipeline {
    agent any
    
    stages {
        stage('checkout') {
            steps {
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git']])
            }
        }
        
        stage('clone') {
            steps {
                git branch: 'main', credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git'
            }
        }
        stage('Cppcheck') {
            steps {
                bat 'cppcheck --platform=win64 --inconclusive --enable=all --xml-version=2 --xml cppcheck.xml'
            }
        }
        stage('Read cppcheck.xml') {
            steps {
                script{
                def xml = readFile 'cppcheck.xml'
                echo xml.errors
                    }
            }
        }
    }
    post {
        always {
            publishCppcheck pattern:'cppcheck.xml'
        }
    }
}
